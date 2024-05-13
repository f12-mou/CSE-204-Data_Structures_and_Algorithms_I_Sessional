#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;
class Ludo
{
private:
    bool* vis;               // Boolean array to mark visited node or else Unvisited.
    int* pred;               // Preserving the predecessor of each node while finding shortest path.
    int* dist;               // To store the distance from source node after Breadth First Search.
    int numOfLadders;        // Number of Ladders in the Board.
    int numOfSnakes;         // Number of Snakes in the Board.
    int V;                   // Number of nodes or cells in the Board.
    int die;                 // Number of faces in the die.
    map<int,int>snakes;      // Map maintaining the mouth to tail information of each snake.
    map<int,int>ladders;     // Map storing start and end of each ladder.

public:
    Ludo(int n,int x)       // Constructor
    {
        die=n;
        V=x;
        vis = new bool[V+1];
        pred = new int[V+1];
        dist = new int[V+1];
        for (int i =1; i<= V; i++){
            vis[i] = false;   // Initializing visited array to be false.
            dist[i] = 0;     // Initializing distance array to be zero.
            pred[i] = -1;    // Initializing predecessor of each node to be null.
        }
    }
    void setLadders(int a[],int n)
    {
        numOfLadders=n;
        for(int i=1;i<=2*n;i+=2)
        {
            // Consecutive odd and even index representing start and end of a ladder.
            std::map<int,int>::iterator itr;
            itr=ladders.find(a[i]);
            if(itr!=ladders.end())  // If two ladders start from the same cell, one might want to go to the uppermost!!
                itr->second=max(a[i+1],ladders[a[i]]);
            else
                ladders.insert({a[i],a[i+1]});
        }

    }
    void setSnakes(int a[],int n)
    {
        numOfSnakes = n;
        for(int i=1;i<=2*n;i+=2)
        {
            snakes.insert({a[i],a[i+1]}); // Consecutive odd and even index representing start and end of a Snake.
        }
    }
    void setProperty(int v, int u, int addend)  // while BFS, necessary changes are made to the nodes.
    {
        vis[v] = true;
        dist[v] = dist[u] + addend;     // Here addend can be 0 for ladder and snake
        pred[v]=u;                      // and 1 when moving from one cell to another by die Roll
    }
    void bfs()
    {
        queue<int>q;
        vis[1] = true;
        dist[1] = 0;
        q.push(1);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if(snakes.find(u)!=snakes.end())
            {
                int z=snakes[u];
                if (vis[z] == false)
                {
                    setProperty(z,u,0);
                    q.push(z);
                }
            }
            else if(ladders.find(u)!=ladders.end())
            {
                int z=ladders[u];
                if (vis[z] == false)
                {
                    setProperty(z,u,0);
                    q.push(z);
                }
            }
            else
            {
                for(int z = u+1; z<=(u+die) && z<=V ;z++)
                {
                    if (vis[z] == false) {
                        setProperty(z,u,1);
                        q.push(z);
                    }
                }
            }
        }
    }
    int getDistance()
    {
        if(vis[V]==true)
            return dist[V];
        return -1;
    }
    vector<int> printPath()
    {
        stack<int>s;    // To Reverse the path from destination to source.
        vector<int>ss;  // Vector containing the sequence of nodes from source to destination.
        if(vis[V]==true)
        {
            int z=V;
            s.push(z);
            while(z!=1)
            {
                z=pred[z];
                s.push(z);
            }
            while(s.empty()==false)
            {
                int y=s.top();
                //cout<<y<<" ";     // Backup for console Printing and Simulation.
                ss.push_back(y);
                s.pop();
            }
             //cout<<endl;          // Backup for console Printing and Simulation.
        }
       return ss;
    }
    vector<int> printUnvis()
    {
        vector<int>unVis;
        for(int i=1;i<=V;i++)
        {
            if(vis[i]==false){  // The nodes are unvisited despite running a BFS from source node.
                unVis.push_back(i);
                //cout<<i<<endl;
            }
        }
        return unVis;
    }
};
int main()
{
    string filename("InputLudo.txt");       // Input File
    string filename2("OutputLudo.txt");     // Output File
    ifstream input_file(filename);
    ofstream output_file(filename2);
    if (!input_file.is_open() || !output_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }
    int t;
    input_file>>t;          // Number of test cases.
    while(t--)
    {
        int n,x,l,s;
        input_file>>n>>x;   // n means number of faces in die and x the number of cells.
        input_file>>l;      // The number of ladders.
        int a[2*l+1];
        for(int i=1;i<=l*2;i+=2)
            input_file>>a[i]>>a[i+1];   // Array holding the start and end of a ladder
        input_file>>s;
        int b[2*s+1];
        for(int i=1;i<=s*2;i+=2)
            input_file>>b[i]>>b[i+1];   // Array holding the start and end of a snake.
        Ludo d(n,x);                    // Processing starts here.
        d.setLadders(a,l);
        d.setSnakes(b,s);
        d.bfs();                         // Processing ends after BFS.
        int dis=d.getDistance();
        cout<<dis<<endl;
        output_file<<dis<<"\n";
        vector<int>path;
        vector<int>unvisited;
        path=d.printPath();
        unvisited=d.printUnvis();
        string ss,aa;
        int flag=1;
        if(path.size()!=0){
            for(auto x:path)
            {
                if(flag==1)
                {
                    flag=2;
                    aa=to_string(x);
                    ss+=aa;
                    continue;
                }
                aa=to_string(x);
                ss+=" -> ";
                ss+=aa;
            }
            output_file<<ss<<"\n";
        }
        else
            output_file<<"No Solution\n";
        ss="";
        if(unvisited.size()!=0){
            for(auto x:unvisited)
            {
                aa=to_string(x);
                ss+=aa;
                ss+=" ";
            }
            output_file<<ss<<"\n";
        }
        else
            output_file<<"All Reachable\n";
    }
    input_file.close();
    output_file.close();
    return 0;
}
