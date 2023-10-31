// 僕の憧れた人、君だ
/* #include <bits/stdc++.h>
using namespace std;
vector<int> add(vector<int> &a, vector<int> &b)
{
  vector<int> c;
  int t = 0;
  int n = a.size() - 1;
  int m = b.size() - 1;
  for (int i = 0; i < n; i++)
  {
    if (i < n)
      t += a[i];
    if (i < m)
      t += b[i];
    c.push_back(t % 10);
    t /= 10;
  }
  if (t)
    c.push_back(t);
  while (c.size() > 1 && c.back() == 0)
    c.pop_back();
  return c;
}
vector<int> sub(vector<int> &a, vector<int> &b)
{
  vector<int> c;
  int t = 0;
  int n = a.size() - 1;
  int m = b.size() - 1;
  for (int i = 0; i < n; i++)
  {
    t = a[i] - t;
    if (i < m)
      t -= b[i];
    c.push_back((t + 10) % 10);
    if (t >= 0)
      t = 0;
    else
      t = 1;
  }
  while (c.size() > 1 && c.back() == 0)
  {
    c.pop_back();
  }
  return c;
}
vector<int> mul(vector<int> &a, long long b)
{
  long long t = 0;
  vector<int> c;
  int t = 0;
  for (int i = 0; i < a.size() || t; i++)
  {
    if (i < a.size())
      t += a[i] * b;
    c.push_back(t % 10);
    t /= 10;
  }
  while (c.size() > 1 && c.back() == 0)
    c.pop_back();
  return c;
}
vector<int> div(vector<int> &a, int b, int &r)
{
  vector<int> c;
  for (int i = 0; i < c.size(); i++)
  {
    r = r * 10 + a[i];
    c.push_back(r / b);
    r %= b;
  }
  while (c.size() > 1 && c.back() == 0)
  {
    c.pop_back();
  }
  return c;
}
int main()
{
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
vector<int> add(vector<int> &a, vector<int> &b)
{
  vector<int> c;
  int t = 0;
  for (int i = 0; i < a.size() || i < b.size(); i++)
  {
    if (i < a.size())
      t += a[i];
    if (i < b.size())
      t += b[i];
    c.push_back(t % 10);
    t /= 10;
  }
  if (t)
    c.push_back(1);
  return c;
}
vector<int> mul(vector<int> &a, int b)
{
  int t = 0;
  vector<int> c;
  for (int i = 0; i < a.size() || t; i++)
  {
    if (i < a.size())
      t += a[i] * b;
    c.push_back(t % 10);
    t /= 10;
  }
  return c;
}
int main()
{
  int n;
  cin >> n;
  vector<int> a(1, 1), b, c(0, 0);
  for (int i = 1; i <= n; i++)
  {
    a = mul(a, i);
    c = add(a, c);
  }
  for (int i = c.size() - 1; i >= 0; i--)
    cout << c[i];
  return 0;
} */
/* #include <bits/stdc++.h>
using namespace std;
void f()
{
}
typedef struct TBNode
{
  char data;
  int ltag, rtag;
  struct TBNode *lchild, *rchild;
} TBNode;
void f(TBNode *curr, TBNode *prev)
{
  if (curr != NULL)
  {
    f(curr->lchild, prev);
    if (curr->lchild == NULL)
    {
      curr->lchild = prev;
      curr->ltag = 1;
    }
    if (prev != NULL && prev->rchild == NULL)
    {
      prev->rchild = curr;
      prev->rtag == 1;
    }
    prev = curr;
    f(curr->rchild, prev);
  }
}
void f2(TBNode *curr, TBNode *prev)
{
  if (curr != NULL)
  {
    if (curr->lchild == NULL)
    {
      curr->lchild = prev;
      curr->ltag = 1;
    }
    if (prev != NULL && prev->rchild == NULL)
    {
      prev->rchild = curr;
      prev->rtag = 1;
    }
    prev = curr;
    f2(curr->lchild, prev);
    f2(curr->rchild, prev);
  }
}
void f3(TBNode *curr, TBNode *prev)
{
  if (curr != NULL)
  {
    prev = curr;
    f2(curr->lchild, prev);
    f2(curr->rchild, prev);
    if (curr->lchild == NULL)
    {
      curr->lchild = prev;
      curr->ltag = 1;
    }
    if (prev != NULL && prev->rchild == NULL)
    {
      prev->rchild = curr;
      prev->rtag = 1;
    }
  }
}
void print(const deque<int> &d)
{
  for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    cout << *it <<' ';
  cout << endl;
}
int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  deque<int> d(arr, arr + 5);
  d.push_front(3333);
  d[0] = 1000000;
  d.at(0) = 122222;
  print(d);
  d.pop_front();
  d.erase(d.begin()+2, d.end());
  d.insert(d.begin() + 1, 100000);
  d.insert(d.begin(), 11);
  print(d);
  d.clear();
  print(d);
  return 0;
} */

/* #include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
class Stu
{
public:
  string name;
  int mScore;
};

void CreateStu(vector<Stu> &v)
{
  for (int i = 1; i <= 5; i++)
  {
    Stu stu;
    stu.name = "学生" + ('a' + i);
    stu.mScore = i * 10 + i;
    v.push_back(stu);
  }
}
void SetScore(vector<Stu> &v)
{
  float sum = 0;
  for (int i = 2; i <= 4; i++)
  {
    sum += v[i].mScore;
  }
  sum = sum / 4;
  cout << sum << endl;
}
bool compare(Stu &a, Stu &b)
{
  return a.mScore > b.mScore;
}
void ShowScore(vector<Stu> &v)
{
  sread((unsigned int)time(NULL));
  for (vector<Stu>::iterator it = v.begin(); it != v.end(); it++)
  {
    deque<int> d;
    int sum = 0;
    for (int i = 1; i <= 10; i++)
    {
      int score = read() % 70 + 30;
      sum += score;
      d.push_back(score);
    }
    sort(d.begin(), d.end());
    sum -= d.front();
    sum -= d.back();
    d.pop_front();
    d.pop_back();
    (*it).mScore = sum / 8;
  }
  sort(v.begin(), v.end(), compare);
}
 void test()
{
  vector<Stu> v;
  CreateStu(v);
  SetScore(v);
  ShowScore(v);
}
void test2()
{
  list<int> l;
  for (int i = 1; i <= 10; i++)
    l.push_back(i);
  //sort(l.begin(), l.end());
  list<int>::iterator it = l.begin();
  for (it; it != l.end();it++)
    cout << *it << endl;
}
int main()
{
  test2();
  return 0;
} */

/* #include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
const int N(1e2);
class graph1
{
public:
  int vex[N];
  int edge[N][N];
  int vexnum;
  int arcnum;

public:
};
class graph2
{
private:
  typedef struct ArcNode
  {
    int adjvex;
    struct ArcNode *next;

  } ArcNode;
  typedef struct vNode
  {
    int data;
    ArcNode *first;
  } vNode, AdjList[100];
  typedef struct
  {
    AdjList vertices;
    int vexnum, arcnum;
  } Algraph;
};
void BFS(graph1 g)
{
  deque<int> deq;
  vector<bool> visited(20, false);
  for (int i = 0; i < vexnums; i++)
  {
    if (!visited[i])
    {
      visited[i] = true;
      deq.push_back(g.vex[i]);
      cout << g.vex[i] << ' ';
      while (!deq.empty())
      {
        deq.pop_front();
        for (int j = 0; j < vexnum; j++)
        {
          if (g.edge[i][j] == 1 && !visited[j])
          {
            visited[j] = true;
            cout << g.vex[j] << ' ';
            deq.push_back(j);
          }
        }
      }
    }
  }
}
int main()
{

  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> singleNumber(vector<int> &nums)
  {
    unordered_map<int, int> map;
    for (auto i:nums)
      ++map[nums];
    vector<int> ans;
    for(auto i:map){
      if(i.second==1)
        ans.push_back(i.first);
    }
    return ans;
  }
};

int main()
{
  int num = 28;
  bitset<4> a(num);
  cout << a << endl; // 将num转换为8位二进制表示形式
  int t = num | (1 << 1);
  bitset<4> z(t);
  cout << z << endl;
  bitset<4> q(num & ~(1 << 1));
  cout << q << endl;
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
vector<int> v[250];
vector<bool> vd(250, false);
void DFS(int x){
  cout << x << ' ';
  vd[x] = true;
  int len = v[x].size();
  for (int i = 0; i < len;i++)
  if(!vd[v[x][i]])
    DFS(v[x][i]);
}
int n,m;
int main(){

  cin >> n>>m;
  for (int i = 0; i < m;i++)
  {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  DFS(1);
  return 0;
} */

/* #include<bits/stdc++.h>
using namespace std;
list<int> mylist{1,1,1,2,3,4,5};
void print(list<int>&l){
  auto it = l.begin();
  for (; it != l.end();it++)
    cout << *it << ' ';
  cout << endl;
}
vector<int> s{1, 2, 3, 5};
int main(){
  print(mylist);
  mylist.push_back(1000);
  print(mylist);
  mylist.pop_back();
  print(mylist);
  mylist.push_front(1000);
  print(mylist);
  //mylist.clear();
  //print(mylist);
  mylist.push_front(1000);
  mylist.push_front(1000);
  mylist.push_front(1000);
  mylist.push_front(1000);
  mylist.push_front(1000);
  cout << mylist.size() << endl;
  print(mylist);
  //mylist.push_front(1000);
  mylist.insert(++mylist.begin(), s.begin(), s.end());
  mylist.remove(1000);
  print(mylist);
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
void test(){
  map<int, string> map;
  map.insert(pair<int,string>(22,"jjj"));
  map.insert(make_pair(1, "tensei"));
  map.insert(make_pair(2, "tensei2"));
  map.insert(make_pair(3, "tensei3"));
  map.insert(make_pair(3, "tensei4"));
  map.insert(make_pair(4, "tensei5"));
  map.insert(make_pair(5, "tenseiy"));
  map.insert(make_pair(6, "tenseit"));
  map.insert(make_pair(1, "tenseir"));
  map[4] = "ddd";
  print(map);
}
void print(map<int,string>&m){
  for (auto it = m.begin(); it != m.end();it++)
    cout << (*it).second << endl;
  cout << endl;
}
struct compare{
  bool operator()(person a,person b)const{
    return a.age > b.age;
  }
};
class person{
  public:
    int age;
    char name[100];
};
set<person, compare> set1;

list<int> mylist;
set<int> set1{1};
multiset<int> set2{1};
void print(set<int> &s)
{
  for (auto it = s.begin(); it != s.end(); it++)
    cout << *it << ' ';
  cout << endl;
}
void print(multiset<int> &s)
{
  for (auto it = s.begin(); it != s.end(); it++)
    cout << *it << ' ';
  cout << endl;
}
struct myfunc{
  bool operator()(int v1,int v2)const{
    return v1 > v2;
  }
};
//改变排序规则；
void print(set<int,myfunc> &s)
{
  for (auto it = s.begin(); it != s.end(); it++)
    cout << *it << ' ';
  cout << endl;
}
int main()
{
  test();
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
class Maker{
  public:
  int  getID(){

    cout << id << endl;
    return id;
  }
  string getName(){
    cout << mName << endl;
    return mName;
  }
  Maker(int a,string b,int c){
    mAge = a;
    mName = b;
    id = c;
  }
  private:
    int mAge;
    string mName;
    int id;
};
class student
{
public:
  int age;
  string name;
  int id;

public:
  student(int a, string b, int c)
  {
    age = a;
    name = b;
    id = c;
  }
  void getData(student &s){
    cout << s.age << endl;
    cout << s.name << endl;
    cout << s.id << endl;
  }
};
class Circle
{
public:
  double mr;

public:
  void setR(double r)
  {
    mr = r;
  }
  double getL()
  {
    return 2 * 3.14 * mr;
  }
};
void test()
{
  Circle c;
  c.setR(1.0);
  cout << c.getL() << endl;
  student s(18, "tensei", 10001);
  s.getData(s);
}
class a{
  int a;
  int b;
  int c = 1;
};
int main()
{
  Maker class1(12,"小吴先生",100086);
  cout << class1.getName() << endl;
  //test();
  return 0;
} */

// BFS
/* #include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int node)
{
  visited[node] = true;
  cout << node << " ";
  for (int neighbor : graph[node])
  {
    if (!visited[neighbor])
    {
      dfs(graph, visited, neighbor);
    }
  }
}

int main()
{
  int num_nodes, num_edges;
  cin >> num_nodes >> num_edges;
  vector<vector<int>> graph(num_nodes);
  for (int i = 0; i < num_edges; i++)
  {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  vector<bool> visited(num_nodes);
  for (int i = 0; i < num_nodes; i++)
  {
    if (!visited[i])
    {
      dfs(graph, visited, i);
    }
  }
  return 0;
}

// BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(vector<vector<int>> &g, vector<bool> &visited, int start)
{
  queue<int> que;
  que.push(start);
  visited[start] = true;
  while (!que.empty())
  {
    int node = que.front();
    que.pop();
    cout << node << ' ';
    for (auto i : g[node])
    {
      if (!visited[i])
      {
        visited[i] = true;
        que.push(i);
      }
    }
  }
}
int main()
{
  int num_v, num_e;
  cin >> num_v >> num_e;
  vector<vector<int>> g(num_v);
  vector<bool> visited(num_v, false);
  for (int i = 0; i < num_e; i++)
  {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 0; i < num_v; i++)
  {
    if (!visited[i])
    {
      bfs(g, visited, i);
    }
  }
  return 0;
}
 */

/* #include <bits/stdc++.h>
using namespace std;
class Maker
{
public:
  int mage;
  Maker(const Maker &other)
  {
    mage = other.mage;
    cout << "拷贝构造" << endl;
  }
  Maker(int age)
  {
    mage = age;
  }
  Maker()
  {
    mage = 0;
    cout << "构造" << endl;
  }
  ~Maker()
  {
    cout << "析构" << endl;
  }
};
class Maker2
{
public:
  char *mp;
  int mage;

public:
  Maker2(const char *p, int age)
  {
    cout << "有参构造" << endl;
    mp = (char *)malloc(sizeof(p) * 5);
    // mp = p;
    strcpy(mp, p);
    mage = age;
  }
  Maker2(const Maker2 &other)
  {
    mp = (char *)malloc(strlen(other.mp) + 1);
    strcpy(mp, other.mp);
    mage = other.mage;
  }
  void print()
  {
    cout << *mp << endl;
  }
  ~Maker2()
  {
    if (mp != NULL)
      cout << "析构" << endl;
    mp = NULL;
  }
};
class m
{
public:
  int a;
};
class a
{
public:
  a()
  {
    cout << "gouz" << endl;
  }
  ~a()
  {
    cout << "xig" << endl;
  }

public:
  int c;
  char b;
};
void test()
{
  int *p = new int[10]{1, 2, 3, 4, 5, 6};
  for (int i = 0; i < 10; i++)
    p[i] = i;
  p[0] = 1;
  cout << p[3] << endl;
}
class b
{
public:
  int a;
  char ch;
  static int t;
  static void fun()
  {
    t = 100;
    cout << t << endl;
  }
};
void test2()
{
  b::fun();
}
int main()
{
  // auto m = (a *)malloc(sizeof(a));
  //  auto t = new a;
  //  delete t;
  test2();
  // Maker2 s("haha", 18);
  // Maker2 s2(s);
  // cout << s2.mage << endl;
  // cout << *(s2.mp) << endl;
  // cout << s.a << endl;
  //  Maker2 class2("haha", 18);
  // class2.print();
  // cout << b << endl;
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
class Maker
{
public:
  mutable int a;
  string b;
  Maker(int a,string b){
    this->a = a;
    this->b = b;
    cout << "构造" << endl;
  }
  void print()const
  {
    a = 10;
    cout << this->a << endl;
  }
};
class neko{
  public:
    int Lg;
    int sc;
};
int main()
{
  Maker class1(69, "老同志");
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
class MyArray
{
public:
  MyArray()
  {
    this->mCapacity = 20;
    this->mSize = 0;
    this->parr = new int[this->mCapacity];
    for (int i = 0; i < this->mCapacity; i++)
      this->parr[i] = i;
  }
  ~MyArray()
  {
    if (this->parr != NULL)
    {
      delete[] this->parr;
      this->parr = NULL;
    }
  };
  MyArray(const MyArray &arr)
  {
    this->mCapacity = arr.mCapacity;
    this->mSize = arr.mSize;
    this->parr = new int[arr.mCapacity];
    for (int i = 0; i < arr.mCapacity; i++)
    {
      this->parr[i] = arr.parr[i];
    }
  }
  MyArray(int capacity, int val)
  {
    this->mCapacity = capacity;
    this->mSize = capacity;
    this->parr = new int[capacity];
    for (int i = 0; i < capacity; i++)
      this->parr[i] = val;
  };
  // 头插法；
  void pushfront(int val)
  {
    if (this->mSize == this->mCapacity)
      return;
    for (int i = this->mSize - 1; i >= 0; i--)
    {
      this->parr[i + 1] = this->parr[i];
    }
    this->parr[0] = val;
    ;
  }
  void pushback(int val)
  {
    if (this->mSize < this->mCapacity)
      this->parr[++mSize] = val;
    else
      return;
  };
  void popfront()
  {
    if (this->mSize == 0)
      return;
    for (int i = 0; i < this->mSize; i++)
      this->parr[i] = this->parr[i + 1];
    this->msize -= 1;
  };
  void popback(){

  };
  int getsize()
  {
    return this->mSize;
  };
  int getCapacity()
  {
    return this->mCapacity;
  };
  void Insert(int pos, int val){};
  int &Get(int pos)
  {
    return this->parr[pos];
  };
  void Set(int pos, int val)
  {
    if (pos < 0 || pos > this->mCapacity - 1)
      return;
    this->parr[pos] = val;
  };
  void print(int pos)
  {
    cout << this->parr[pos] << endl;
    ;
  }
  void print()
  {
    for (int i = 0; i < this->mCapacity; i++)
      cout << this->parr[i] << ' ';
    cout << endl;
  };

private:
  int *parr;
  int mSize;
  int mCapacity;
};
class Maker
{
public:
  int id;
  int age;
  Maker(int age, int id)
  {
    this->id = id;
    this->age = age;
  }
};
Maker operator+(Maker &a, Maker &b)
{
  Maker temp(a.age + b.age, a.id + b.id);
  return temp;
}
int main()
{
  MyArray arr(10, 0);
  arr.print(3);
  arr.print();
  for (int i = 0; i < arr.getsize(); i++)
  {
    arr.Get(i) = i + 10;
  }
  arr.print();
  arr.pushfront(1111);
  arr.print();
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
const int N(1e2);
class graph
{
public:
  int numVex = 0, numEdge = 0;
  int arc[N][N];
  int vexs[N];
};
void prim(graph g)
{
  int adj[N];
  int lowcost[N];
  adj[0] = 0;
  for (int i = 1; i < N; i++)
  {
    adj[i] = 0;
    lowcost[i] = g.arc[0][i];
  }
  for (int i = 1; i < N;i++){
    int k = 0, min = 141514;
    for (int j = 1; j < N;j++){
      if(lowcost[j]<min){
        min = lowcost[j];
        k = j;
      }
    }
    cout << lowcost[k] << k << endl;
    lowcost[k] = 0;
    for (int j = 1; j < N;j++){
      if(lowcost[j]!=0&&lowcost[j]>g.arc[k][j])
      {
        lowcost[j] = g.arc[k][j];
        adj[j] = k;
      }
    }
  }
}
int main()
{
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
const int N(1e3 + 2), M(2e5 + 4);
int arc[N][M] = {0};
int n, m; */
/* void prim()
{
  int sum = 0;
  vector<int> adj(4);
  vector<int> lowcost(4);
  adj[0] = 0;
  lowcost[0] = 0;
  for (int i = 1; i < n; i++)
  {
    adj[i] = 0;
    lowcost[i] = arc[0][i];
  }
  for (int i = 1; i < n; i++)
  {
    int k = 0,min = 1e5;
    for (int j = 1; j < n; j++)
    {
      if (lowcost[j] < min)
      {
        min = lowcost[j];
        k = j;
      }
    }
    sum += lowcost[k];
    lowcost[k] = 0;
    for (int j = 1; j < n;j++){
      if(lowcost[j]>arc[k][j]){
        adj[j] = k;
        lowcost[j] = arc[k][j];
      }
    }
  }
  cout << sum << endl;
}
int main()
{
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    arc[x][y] = z;
    arc[y][x] = z;
  }
 prim();
  return 0;
} */
/* #include <bits/stdc++.h>
using namespace std;
struct Node
{
  int y, v;
  Node(int _y, int _v)
  {
    y = _y;
    v = _v;
  };
};
const int N(5e3+4),M(2e5+5);
vector<Node> edge[M];
int n, m;
vector<bool> b(N, false);
vector<int> dist(N, 127);
int prim()
{
  int ans = 0;
  dist[1] = 0;
  for (int i = 1; i <= n; i++)
  {
    int x = -1;
    for (int j = 1; j <= n; j++)
    {
      if (!b[j] && dist[j] < 1 << 30)
        if (x == -1 || dist[j] < dist[x])
        {
          x =j;
        }
    }
    b[x] = true;
    ans += dist[x];
    for (auto j : edge[x])
    {
      dist[j.y] = min(dist[j.y], j.v);
    }
  }
  return ans;
}
struct Node2{
  int x, y, v;
  bool operator<(const Node2&A)const{
    return v < A.v;
  };
}a[M];
int n, m, fa[N];
int findset(int i){
  if(i==fa[i])
    return i;
  return fa[i] = findset(fa[i]);
}
void Krustal(){
  for (int i = 1; i <= n;i++)
    fa[i] = i;
  sort(a + 1, a + m + 1);
  int ans = 0;
  for (int i = 1; i <= m;i++){
    int x = findset(a[i].x), y = findset(a[i].v);
    if(x!=y){
      fa[x] = y;
      ans += a[i].v;
    }
  }
  cout << ans << endl;
}

int main()
{
  cin >> n >> m;
  for (int i = 1; i <= m;i++){
    int x, y, z;
    cin >> x >> y >> z;
    edge[x].push_back(Node(y, z));
    edge[y].push_back(Node(x, z));
  }
  cout<<prim()<<endl;
  return 0;
} */
/* #include <bits/stdc++.h>
using namespace std;
struct Node
{
  int y, v;
  Node(int _y, int _v)
  {
    y = _y;
    v = _v;
  };
};
const int N(1e9);
vector<Node> edge[N + 1];
int n, m;
vector<bool> b(N + 1, false);
vector<int> dist(N + 1, 127);
int dijkstra(int s, int t)
{
  dist[s] = 0;
  for (;;)
  {
    int x = -1;
    for (int i = 1; i <= n; i++)
    {
      if (!b[i] && dist[i] < 1 << 30)
      {
        if (x == -1 || dist[i] < dist[x])
          x = i;
      }
    }
    if (x == t || x == -1)
    {
      break;
    }
    b[x] = true;
    for (auto i : edge[x])
    {
      dist[i.y] = min(dist[i.y], dist[x] + i.v);
    }
  }
  return dist[t];
}


struct edge
{
  int v, w;
};

vector<edge> e[maxn];
int dis[maxn], vis[maxn];

void dijkstra(int n, int s)
{
  memset(dis, 63, sizeof(dis));
  dis[s] = 0;
  for (int i = 1; i <= n; i++)
  {
    int u = 0, mind = 0x3f3f3f3f;
    for (int j = 1; j <= n; j++)
      if (!vis[j] && dis[j] < mind)
        u = j, mind = dis[j];
    vis[u] = true;
    for (auto ed : e[u])
    {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w)
        dis[v] = dis[u] + w;
    }
  } */

/* #include <bits/stdc++.h>
using namespace std;
const int N(1e3);

vector<int> edge[N + 1];
int n, m, q[N + 1], d[N + 1];
void Toppsort()
{
  int front = 1, rear = 0;
  for (int i = 1; i <= n; i++)
  {
    if (d[i] == 0)
    {
      q[++rear] = i;
    }
    while (front <= rear)
    {
      int x = q[front];
      ++front;
      for (auto y : edge[x])
      {
        if (--d[y] == 0)
        {
          q[++rear] = y;
        }
      }
    }
  }
  if (rear == n)
    cout << "YEs" << endl;
  else
    cout << "NO" << endl;
}
int main()
{

  return 0;
}



class Solution
{
public:
  int numIslands(vector<vector<char>> &grid)
  {
    int nr = grid.size();
    if (!nr)
      return 0;
    int nc = grid[0].size();

    int num_islands = 0;
    for (int r = 0; r < nr; ++r)
    {
      for (int c = 0; c < nc; ++c)
      {
        if (grid[r][c] == '1')
        {
          ++num_islands;
          grid[r][c] = '0';
          queue<pair<int, int>> neighbors;
          neighbors.push({r, c});
          while (!neighbors.empty())
          {
            auto rc = neighbors.front();
            neighbors.pop();
            int row = rc.first, col = rc.second;
            if (row - 1 >= 0 && grid[row - 1][col] == '1')
            {
              neighbors.push({row - 1, col});
              grid[row - 1][col] = '0';
            }
            if (row + 1 < nr && grid[row + 1][col] == '1')
            {
              neighbors.push({row + 1, col});
              grid[row + 1][col] = '0';
            }
            if (col - 1 >= 0 && grid[row][col - 1] == '1')
            {
              neighbors.push({row, col - 1});
              grid[row][col - 1] = '0';
            }
            if (col + 1 < nc && grid[row][col + 1] == '1')
            {
              neighbors.push({row, col + 1});
              grid[row][col + 1] = '0';
            }
          }
        }
      }
    }

    return num_islands;
  }
};
class Solution
{
private:
  void dfs(vector<vector<char>> &grid, int r, int c)
  {
    int nr = grid.size();
    int nc = grid[0].size();

    grid[r][c] = '0';
    if (r - 1 >= 0 && grid[r - 1][c] == '1')
      dfs(grid, r - 1, c);
    if (r + 1 < nr && grid[r + 1][c] == '1')
      dfs(grid, r + 1, c);
    if (c - 1 >= 0 && grid[r][c - 1] == '1')
      dfs(grid, r, c - 1);
    if (c + 1 < nc && grid[r][c + 1] == '1')
      dfs(grid, r, c + 1);
  }

public:
  int numIslands(vector<vector<char>> &grid)
  {
    int nr = grid.size();
    if (!nr)
      return 0;
    int nc = grid[0].size();

    int num_islands = 0;
    for (int r = 0; r < nr; ++r)
    {
      for (int c = 0; c < nc; ++c)
      {
        if (grid[r][c] == '1')
        {
          ++num_islands;
          dfs(grid, r, c);
        }
      }
    }

    return num_islands;
  }
}; */

#include <bits/stdc++.h>
using namespace std;
/* const int maxn(1e3);
int fa[maxn + 1];  // fa数组记录代表元；(father)
int sz[maxn + 1];  // 记录每个集合的元素个数；
int dep[maxn + 1]; // 记录每个集合的深度；
// 初始化
void initialize(int n)
{
  for (int i = 1; i <= n; i++)
  {
    fa[i] = i;
    sz[i] = dep[i] = 1;
  }
}
// 集合合并
int findset(int x)
{
  if (fa[x] == x)
    return x;
  return findset(fa[x]); // 找到x的祖先的代表元；
}
int findset(int x)
{
  if (x == fa[x])
    return x;
  fa[x] = findset(fa[x]);
  return fa[x];
}
void unionset(int x, int y)
{
  int fx = findset(x), fy = findset(y); // 找到代表元；
  if (fx == fy)
  {
    return;
  }
  fa[fx] = fy;
}
void uninoset(int x, int y)
{
  int fx = findset(x), fy = findset(y);
  if (fx == fy)
    return;
  if (dep[fx] > dep[fy])
    swap(fx, fy);
  fa[fx] = fy;
  if (dep[fx] == dep[fy])
    dep[fy]++;
  return;
}
 */
/* int t, n, fa[1001], a[1001][3];
int findset(int x)
{
  if (x == fa[x])
    return x;
  fa[x] = findset(fa[x]);
  return fa[x];
}
int main()
{
  cin >> t;
  while (t--)
  {
    int xe, ye, r;
    cin >> xe >> ye;
    cin >> n;
    a[0][0] = 0, a[0][1] = 0, a[0][2] = 1;
    for (int i = 0; i <= n; i++)
    {
      fa[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    for (int i = 0; i <= n; i++)
    {
      for (int j = i + 1; j <= n; j++)
      {
        if (1LL * (a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) + 1LL * (a[i][1] - a[j][1]) * (a[i][1] - a[j][1]) <= 1LL * (a[i][2] + a[j][2]) * (a[i][2] + a[j][2]))
        {
          int fi = findset(i), fj = findset(j);
          if (fi == fj)
            continue;
          fa[fi] = fj;
        }
      }
    }
    int idx = -1;
    for (int i = 0; i <= n; i++)
    {
      if (1LL * (a[i][0] - xe) * (a[i][0] - xe) + 1LL * (a[i][1] - ye) * (a[i][1] - ye) <= 1LL * a[i][2] * a[i][2])
        idx = i;
    }
    if (idx != -1 && findset(0) == findset(idx))
      cout << "1" << endl;
    else
      cout << '0' << endl;
  }
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
const int N(5e3 + 2);
// vector<int> fa, a[N];
int fa[N];
int n, m, p;
int findset(int i)
{
  if (i == fa[i])
    return i;
  fa[i] = findset(fa[i]);
  return fa[i];
}
int main()
{
  cin >> n >> m >> p;
  // fa.resize(n + 1);
  for (int i = 0; i <=n+10; i++)
  {
    fa[i] = i;
  }
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    int fx = findset(x), fy = findset(y);
    if (fx == fy)
      continue;
    fa[fx] = fy;
  }
  while (p--)
  {
    int x, y;
    cin >> x >> y;
    if (findset(x) == findset(y))
      cout << "Yes" << endl;
    else
      cout << "N0" << endl;
  }
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
const int N(1e4);
int n, m;
int fa[N];
 int findset(int x){
  if(x==fa[x])
    return x;
  fa[x] = findset(fa[x]);
  return fa[x];
}
int findset(int x){
  if(x!=fa[x])
    fa[x] = findset(fa[x]);
  return fa[x];
}
int main()
{
  while (true)
  {
    cin >> n >> m;
    if(n==0)
      break;
    for (int i = 1; i <= n; i++)
    {
      fa[i] = i;
    }
    while (m--)
    {
      int x, y;
      cin >> x >> y;
      int fx = findset(x), fy = findset(y);
      if (fx == fy)
        continue;
      fa[fy] = fx;
    }
    int cnt = 0;
    for (int i = 1; i <= n;i++)
    if(fa[i]==i)
        cnt++;
    cout <<  cnt-1 << endl;
  }
  return 0;
} */
/* #include <bits/stdc++.h>
using namespace std;
// vector<int> fa;
int n, m, p, q;
map<int, int> fa;
int findset(int x)
{
  if (x != fa[x])
    fa[x] = findset(fa[x]);
  return fa[x];
}
int main()
{
  cin >> n >> m >> p >> q;
  for (int i = m * -1; i <= n; i++)
  {
    fa[i] = i;
  }
  for (int i = 1; i <= p + q; i++)
  {
    int x, y;
    cin >> x >> y;
    int fx = findset(x), fy = findset(y);
    if (fx == fy)
      continue;
    fa[fx] = fy;
  }
  int res1 = 0, res2 = 0;
  for (int i = -1 * m; i <= -1; i++)
    if (findset(fa[i])==findset(-1))
    {
      res1++;
    }
  for (int i = 1; i <= n; i++)
    if ((findset(fa[i]) == findset(1)))
      res2++;
  cout << min(res1, res2) << endl;
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
vector<int> add(vector<int> &a, vector<int> &b)
{
  vector<int> c;
  int t = 0;
  for (int i = 0; i < a.size() || i < b.size(); i++)
  {
    if (i < a.size())
      t += a[i];
    if (i < b.size())
      t += b[i];
    c.push_back(t % 10);
    t /= 10;
  }
  if (t)
  {
    c.push_back(t);
  }
  while (c.size() > 1 && c.back() == 0)
    c.pop_back();
  return c;
}
vector<int> mul(vector<int> &a, int b)
{
  vector<int> c;
  int t = 0;
  for (int i = 0; i < a.size() || t; i++)
  {
    if (i < a.size())
      t += a[i] * b;
    c.push_back(t % 10);
    t /= 10;
  }
  while (c.size() > 1 && c.back() == 0)
    c.pop_back();
  return c;
}
vector<int> sub(vector<int> &a, vector<int> &b)
{
  vector<int> c;
  int t = 0;
  for (int i = 0; i < a.size(); i++)
  {
    t = a[i] - t;
    if (i < b.size())
      t -= b[i];
    c.push_back(t + 10 % 10);
    if (t < 0)
      t = 1;
    else
      t = 0;
  }
  while (c.size() > 1 && c.back() == 0)
  {
    c.pop_back();
  }
  return c;
}
bool cmp(vector<int> &a, vector<int> &b)
{
  int n = a.size();
  int m = b.size();
  if (n != m)
    return n > m;
  for (int i = 0; i < n; i++)
  {
    if (a[i] != b[i])
      return a[i] > b[i];
  }
  return true;
}

vector<int> c(vector<int> &a, int &r, int b)
{
  vector<int> c;

  for (int i = a.size() - 1; i >= 0; i--)
  {
    r = r * 10 + a[i];
    c.push_back(r / b);
    r %= b;
  }
  reverse(c.begin(), c.end());
  while (c.size() > 1 && c.back() == 0)
    c.pop_back();
  return c;
}
int p;
int main()
{
  cin >> p;
  vector<int> ans{1};
  int t = p / 30;
  for (int i = 1; i <= t; i++)
  {
    ans = mul(ans, 1073741824);
  }
  cout << ans[33] << endl;
  t = p % 30;
  for (int i = 1; i <= t; i++)
  {
    ans = mul(ans, 2);
  }
  t = ans.size();
  if (ans[0] >= 1)
    ans[0] -= 1;
  else
  {
    ans[0] = 9;
    ans[1] -= 1;
  }
  if (t >= 500)
  {
    for (int i = 499; i >= 0; i--)
    {
      cout << ans[i];
    }
    cout << endl;
  }
  else
  {
    int n = 500 - t;
    for (int i = 1; i <= n; i++)
      cout << 0;
    for (int i = n - 1; i >= 0; i--)
      cout << ans[i];
    cout << endl;
  }
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
const int N(1e8 + 3);
bool a[N];
int n;
int main()
{

  cin >> n;
  memset(a, true, sizeof(a));
  a[0] = a[1] = 0;
  int p = 2;
  while (p * p <= n)
  {
    if (a[p] == 1)
    {
      for (int i = p * p; i <= n; i += p)
      {
        a[i] = 0;
      }
    }
    p++;
  }
  int ans = 0;
  for (int i = 2; i <= n; i++)
  {
    if (a[i] == 1)
    {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
 */

/* #include <bits/stdc++.h>
using namespace std;
int n;
const int N(1e8 + 2);
int prime[N];
void is_prime()
{

  prime[0] = prime[1] = 0;
  int p = 2;
  while (p * p <= n)
  {
    if (prime[p] == true)
    {
      for (int i = p * p; i <= n; i += p)
      {
        prime[i] = 0;
      }
    }
    p++;
  }
}
int main()
{
  memset(prime, 1, sizeof(prime));
  scanf("%d", &n);
  is_prime();
  int ans = 0;
  for (int i = 2; i <= n; i++)
  {
    if (prime[i] == 1)
      ans++;
  }
  cout << ans << endl;
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
int n, m;
int ans = 0, res = 0;
const int N(1e6 + 3), M(2e6 + 3);
int a[N][4] = {0};
void dfs(int r, int c, int &ans)
{
  if (r == n && c == 4)
    return;
  if (r + 1 <= n && a[r + 1][c] == 0)
  {
    ans++;
    a[r + 1][c] = 1;
    dfs(r + 1, c, ans);
  }
  else
  {
    ans++;
    if (c + 1 <= 4 && a[r][c + 1] == 0)
    {
      ans++;
      a[r][c + 1] == 1;
      dfs(r, c + 1, ans);
    }
  }
}
int main()
{
  cin >> n >> m;
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    a[x][y] = 1;
  }
  dfs(1, 1, ans);
  dfs(1, 1, res);
  cout << ans << ' ' << res << endl;
  if (ans + res >= 2 * n)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
int a[10001][10001];
int dp[1001];
int n, m;
int main()
{
  cin >> n >> m;
  memset(a, 127, sizeof(a));

  for (int i = 1; i <= m; i++)
  {
    int x, y, z;
    cin >> x >> y;
    a[x][y] = min(a[x][y], z);
  }
  memset(dp, 127, sizeof(dp));
  dp[1] = 0;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j < i; j++)
    {
      if (dp[j] < 1 << 30 && a[j][i] < 1 << 30)
        dp[i] = min(dp[i], dp[j] + a[j][i]);
    }
  cout << dp[n] << endl;
  return 0;
} */

/* #include <iostream>
#include <vector>

// 定义单向循环链表节点
struct Node
{
  int data;                               // 节点数据，即密码值
  Node *next;                             // 指向下一个节点的指针
  Node(int d) : data(d), next(nullptr) {} // 构造函数
};

void josephus_circle(Node *head, int m)
{
  // 计算链表长度
  int len = 0;
  for (Node *p = head; p != nullptr; p = p->next)
  {
    ++len;
  }

  // 特判链表为空或只有一个节点的情况
  if (len <= 1)
  {
    return;
  }

  // 将指针 p 移动到最后一个节点的位置
  Node *p = head;
  while (p->next != nullptr)
  {
    p = p->next;
  }

  // 将尾节点指向头节点，构成单向循环链表
  p->next = head;

  // 开始模拟报数出列过程
  int count = 1;
  p = head;
  while (len > 1)
  {
    // 报数到 m 时删除当前节点
    if (count == m)
    {
      std::cout << p->data << " "; // 输出该节点数据（即编号）
      --len;                       // 链表长度减一
      Node *tmp = p->next;         // 临时保存下一个节点的指针
      *p = *tmp;                   // 将下一个节点复制到当前节点
      delete tmp;                  // 删除下一个节点
      count = 1;                   // 报数重置为 1
    }
    else
    {
      ++count;     // 继续报数
      p = p->next; // 指向下一个节点
    }
  }
  std::cout << p->data << std::endl; // 输出最后一个节点的数据（即编号）
}

int main()
{
  int n, m;
  std::cout << "Input the initial value of m: ";
  std::cin >> m;
  std::cout << "Input the number of people n: ";
  std::cin >> n;

  // 读入每个人的密码值，并构建单向循环链表
  std::vector<int> passwords(n);
  Node *head = nullptr;
  for (int i = 0; i < n; ++i)
  {
    std::cin >> passwords[i];
    if (head == nullptr)
    { // 首次插入节点，生成头节点
      head = new Node(passwords[i]);
    }
    else
    { // 插入其他节点
      Node *p = head;
      while (p->next != nullptr)
      {
        p = p->next;
      }
      p->next = new Node(passwords[i]);
    }
  }

  // 进行约瑟夫环计算，并输出结果
  josephus_circle(head, m);

  // 释放链表内存
  Node *p = head;
  while (p != nullptr)
  {
    Node *tmp = p->next;
    delete p;
    p = tmp;
  }

  return 0;
}
 */

/*
 * 该算法时间复杂度为O(n*m)
 *  空间复杂度为O(n);
 *
 */
/*
#include <iostream>
#include <vector>
using namespace std;

// 循环链表节点类
class ListNode
{
public:
  int value;      // 节点的值（密码）
  ListNode *next; // 指向下一个节点的指针

  // 构造函数，初始化节点
  ListNode(int val)
  {
    value = val;
    next = nullptr;
  }
};

// 循环链表类
class JosephCurcular
{
private:
  ListNode *head; // 链表的头节点指针

public:
  // 构造函数，初始化链表
  JosephCurcular()
  {
    head = nullptr;
  }

  // 创建循环链表并设置密码值
  void createLinkedList(int n, vector<int> &passwords)
  {
    if (n <= 0)
      return;

    // 创建链表的头节点
    head = new ListNode(1);
    ListNode *current = head;

    // 创建剩余的节点，并将其连接到链表中
    for (int i = 1; i < n; i++)
    {
      ListNode *newNode = new ListNode(i + 1);
      current->next = newNode;
      current = current->next;
    }

    // 将链表首尾相连，形成循环链表
    current->next = head;

    // 设置每个节点的密码值
    current = head;
    for (int i = 0; i < n; i++)
    {
      current->value = passwords[i];
      current = current->next;
    }
  }

  // 根据报数规则找到出列顺序并返回
  vector<int> getOrder(int m)
  {
    vector<int> ans;
    if (head == nullptr)
      return ans;
    ListNode *current = head;
    ListNode *prev = nullptr;
    int count = 0;

    // 循环直到链表中只剩下一个节点
    while (current->next != current)
    {
      count++;
      // 当报数达到上限m时，将当前节点从链表中删除，并将其密码添加到顺序中
      if (count == m)
      {
        ans.push_back(current->value);
        // 迭代、更新链表的连接关系，删除出列的节点
        if (prev == nullptr)
        {
          prev = current;
          while (prev->next != current)
            prev = prev->next;
        }
        prev->next = current->next;
        ListNode *temp = current;
        current = current->next;
        //销毁节点，释放内存；
        delete temp;
        count = 0;
      }
      else
      {
        prev = current;
        current = current->next;
      }
    }
    // 添加最后一个出列的人的密码到顺序中
    ans.push_back(current->value);
    delete current;
    head = nullptr;
    return ans;
  }
};

int main()
{


  int n; // 总人数
  int m; // 初始报数上限值

  cout << "请输入总人数n：";
  cin >> n;

  cout << "请输入初始报数上限值m：";
  cin >> m;

  vector<int> passwords(n); // 存储每个人的密码
  cout << "请输入每个人的密码（正整数）：" << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> passwords[i];
  }
  // 创建JosephCurcular类，调用无参构造；
  JosephCurcular linklist;
  //初始化 linklist的成员变量，调用createLinkedlist函数；
  linklist.createLinkedList(n, passwords);
  vector<int> ans = linklist.getOrder(m);
  cout << "出列顺序：";
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
} */

/*
#include <bits/stdc++.h>
using namespace std;
int t, m;
const int M(1e2 + 3);
int val[M], wt[M];
int dp[M][M];
int main()
{
  cin >> t >> m;
  for (int i = 1; i <=m; i++)
    cin >> wt[i] >> val[i];
  for (int i = 0; i <=m; i++)
  {
    dp[i][0] = 0;
    dp[0][i] = 0;
  }
  for (int i = 1; i <=m; i++)
    for (int j = t; j >= 0; j--)
    {
      if (j < wt[i])
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i]] + val[i]);
    }
  cout << dp[m][t] << endl;
  return 0;
}

#include <iostream>
#include <algorithm>
#define MAX 999999
using namespace std;
int N, T, v[MAX], c[MAX], f[MAX], r[MAX], vk[MAX], k1[MAX], ans = MAX, V, K;
int log2(int a);
int main()
{
  int i, j;
  cin >> N >> T;
  for (i = 0; i < N; i++)
  {
    cin >> v[i];
    if (T + v[i] * v[i] > V)
      V = T + v[i] * v[i];
  }
  memset(f, MAX, (V + 1) * sizeof(int));
  memset(r, MAX, (V + 1) * sizeof(int));
  for (i = 0; i < N; i++)
    cin >> c[i];
  r[T] = f[0] = 0;
  // binary
  for (i = 0; i < N; i++)
  {
    int t = 1, temp = c[i];
    while (t < temp)
    {
      vk[K] = v[i] * t;
      k1[K++] = t;
      temp -= t;
      t *= 2;
    }
    vk[K] = v[i] * temp;
    k1[K++] = temp;
  }
  for (i = 0; i < K; i++)
    for (j = V - vk[i]; j >= 0; j--)
      f[j + vk[i]] = min(f[j + vk[i]], f[j] + k1[i]);
  for (i=0;i<N;i++)
      for (j=V;j>=0;j--)
          for (k=1;k<=min(c[i],(V-j)/v[i]);k++)
              f[j+k*v[i]]=min(f[j+k*v[i]],f[j]+k);
  for (i = 0; i < N; i++)
    for (j = T; j <= V; j++)
      r[j + v[i]] = min(r[j + v[i]], r[j] + 1);
  for (i = T; i <= V; i++)
    ans = min(ans, f[i] + r[i]);
  if (ans != MAX)
    cout << ans << endl;
  else
    cout << -1 << endl;
  return 0;
}
int log2(int a)
{
  int i = 1, ans = 0;
  while (i <= a)
  {
    i *= 2;
    ans++;
  }
  return ans - 1;
} */

/* #include <bits/stdc++.h>
using namespace std;
const int N(2e4 + 20);
int a[N];
int v;
int n;
int cmp(int a,int b){
  return a > b;
}
int dp[N];
int main(){
  cin >> v >> n;
  for (int i = 1; i <= n;i++)
    cin >> a[i];
  dp[0] = 0;
  for (int i = 1; i <= n;i++){
    for (int j = v; j >= a[i];j--){
      dp[j] = max(dp[j], dp[j - a[i] ]+ a[i]);
    }
  }
  cout << v - dp[v] << endl;
  return 0;
} */

/*
#include <bits/stdc++.h>
using namespace std;
const int N(2e5 + 4);
int dp[N];
int a[N];
int n;
int main(){
  cin >> n;
  for (int i = 1; i <= n;i++){
    cin >> a[i];
  }
  dp[0] = 0;
  dp[1] = a[1];
  for (int i = 1; i <= n;i++){
    dp[i] = max(a[i], dp[i - 1] + a[i]);
  }
  int ans = INT_MIN;
  for (int i = 1; i <= n;i++)
    ans = max(ans, dp[i]);
  cout << ans << endl;
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
const int N(1e4);
int val[N], dp[N][N],w[N];
int t, n;
int main(){

  cin >> t >> n;
  for (int i = 1; i <= n;i++)
  {
    cin >> val[i] >> w[i];
  }
  for (int i = 1; i <= n;i++){
    dp[i][0] = 0;
    dp[0][i] = 0;
  }
  for (int i = 1; i <= n;i++){
    for (int j = t; j >= 0;j--){
      if(j<val[i]){
        dp[i][j] = dp[i - 1][j];
      }
      else{
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - val[i]] + val[i] * w[i]);
      }
    }
  }
  cout << dp[n][t] << endl;
  return 0;
} */

#/* include <bits/stdc++.h>
using namespace std;
int n, m, vol;
const int N(1e2+10);
int w[N], val[N],fa[N],f[N];
int findset(int x)
{
  if (x != findset(fa[x]))
    fa[x] = findset(fa[x]);
  return fa[x];
}

int main()
{
  vector<int> a;
  a.resize(n + 1);
  cin >> n >> m >> vol;
  for (int i = 1; i <= n; i++)
    fa[i] = i;
  for (int i = 1; i <= n; i++)
  {
    cin >> val[i] >> w[i];
  }
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    int fx = findset(x), fy = findset(fy);
    if (fx != fy)
    {
      val[fy] += val[fx];
      w[fy] += w[fx];
      fa[fx] = fy;
    }
  }
  for (int i = 1; i <= n;i++){
    if(fa[i]==i){
      for (int j = vol; j >= val[i];j--){
        f[j] = max(f[j], f[j - val[i]] + w[i]);
      }
    }
  }
  cout << f[vol] << endl;
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
const int N(1e5 + 3);
int fa[N];
int n, m, p;
int findset(int x){
  if(x!=fa[x])
    fa[x] = findset(fa[x]);
  return fa[x];
}
int main()
{
  cin >> n >> m >> p;
  for (int i = 1; i <= n; i++)
  {
    fa[i] = i;
  }
  for (int i = 1; i <= m; i++)
  {
    int x, y;
    cin >> x >> y;
    int fx = findset(x), fy = findset(y);
    if (fx != fy)
    {
      fa[fx] = fy;
    }
  }
  while (p--)
  {
    int x, y;
    cin >> x >> y;
    if (findset(x) == findset(y))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
const int N(1e4 + 3);
int n, m, p, q;
map<int, int> fa;
int find(int x)
{
  if (x != fa[x])
    fa[x] = find(fa[x]);
  return fa[x];
}
int main()
{
  cin >> n >> m >> p >> q;
  for (int i = -1 * m; i <= n; i++)
    fa[i] = i;
  for (int i = 1; i <= p + q; i++)
  {
    int x, y;
    cin >> x >> y;
    int fx = find(x), fy = find(y);
    if (fx != fy)
      fa[fx] = fy;
  }
  int res1 = 0, res2 = 0;
  cout << find(1) <<' '<< find(-1) << endl;
  for (int i = -1 * m; i <= n; i++)
  {
    if (find(i) == find(-1))
      res1++;
    if (find(i) == find(1))
      res2++;
  }
  cout << min(res1, res2) << endl;
  return 0;
}
 */

/* #include <bits/stdc++.h>
using namespace std;
int n;
vector<string> s(n + 1), ans(n + 1);
vector<int> nxt;
// string ans;
int kmp(string s, string p)
{

  int n = s.size(), m = p.size();
  s += '#';
  s += p;
  nxt.resize(n + m + 1);
  int j = 0;
  for (int i = 1; i <= n + m + 1; i++)
  {
    while (j > 0 && s[j + 1] != s[i])
      j = nxt[j];
    if (s[j + 1] == s[i])
      j++;
    nxt[i] = j;
  }
  int k = 0;
  for (int i = 1; i <= n + m + 1; i++)
  {
    k = max(k, nxt[i]);
  }
  return k;
}
int main()
{
  string ans;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i];
  for (int i = 0; i < n; i++)
  {
    int k = kmp(s[i + 1], s[i]);
    if (k == 0)
    {
      ans += s[i] + s[i + 1];
    }
    else
    {
      string t(s[i + 1].begin() + k, s[i + 1].end());
      ans += s[i] + t;
    }
  }
  cout << ans << endl;
  return 0;
}
 */

/* #include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<string> words_list(n);
  for (int i = 0; i < n; i++)
  {
    cin >> words_list[i];
  }
  while (words_list.size() > 1)
  {
    int i = 0, max_common_len = 0;
    for (int j = 1; j < words_list.size(); j++)
    {
      int common_len = 0;
      while (common_len < words_list[j].size() && words_list[i][words_list[i].size() - common_len - 1] == words_list[j][common_len])
      {
        common_len++;
      }
      if (common_len > max_common_len)
      {
        max_common_len = common_len;
        i = j - 1;
      }
    }
    words_list[i] += words_list[i + 1].substr(max_common_len);
    words_list.erase(words_list.begin() + i + 1);
  }

  cout << words_list[0] << endl;
  return 0;
}
 */

/* #include <bits/stdc++.h>
using namespace std;
int n;
int t;
const int N(2e5 + 4);
char s[N];
int nxt[N];
void kmp(){
  int n = strlen(s + 1);
  s[n + 1] = '#';
  for (int i = n,j=n+2; i >= 0;i--)
    s[j++] = s[i];
  int j = 0;
  for (int i = 2; i <= n+n+1;i++){
    while(j>0&&s[j+1]!=s[i])
      j = nxt[j];
      if(s[j+1]==s[i])
      j++;
      nxt[i] = j;
  }
  int k = 0;
  for (int i = 1; i <= n + n + 1;i++){
      cout << nxt[i] << ' ';
      k = max(k, nxt[i]);
  }
  for (int i = k; i >= 1;i++){
      cout << s[i];
  }
}
int main(){

  cin >> t;
  while(t--){
      scanf("%s", s+1);
      kmp();
      cout << endl;
  }
  return 0;
}  */

/* #include <bits/stdc++.h>
using namespace std;
int n;
const int N(1e6 + 3);
int val[N], h[N];
stack<int> s;
vector<int> ans;
int main()
{

  cin >> n;
  ans.resize(n + 1, 0);
  for (int i = 1; i <= n; i++)
    cin >> h[i] >> val[i];
  for (int i = 1; i <= n; i++)
  {
    int k = 0;
    while (!s.empty() && h[i] > h[s.top()])
    {
     // k += val[s.top()];
     ans[i] += val[s.top()];
     s.pop();
    }
    if(!s.empty())
     ans[i] += val[i];
    //ans.push_back(k);
    s.push(i);
  }
  cout << *(max_element(ans.begin(), ans.end()));
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
int n;
const int N(1e5 + 5);
int h[N];
stack<int> s;
int main()
{

  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> h[i];
  }
  //int ans = 0;
  vector<int> ans(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    while(!s.empty()&&h[i]<=h[s.top()])
    {
      s.pop();
    }
    s.push(i);
    ans[i] = s.size();
  }
  cout << *(max_element(ans.begin(), ans.end()));
  return 0;
  } */
/*
#include <bits/stdc++.h>
using namespace std;
class Maker
{
public:
  int id;
  char *name;

public:
  Maker()
  {
    id = 0;
    name = new char[strlen("NULL")];
    strcpy(name, "NULL");
  }
  Maker(int id, char *name)
  {
    this->id = id;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
  }
  ~Maker()
  {
    this->id = 0;
    delete[] this->name;
    this->name = NULL;
  }
};
// 全局方式
Maker operator+(Maker &a, Maker &b)
{
  Maker temp(a.id + b.id, "");
  return temp;
}
class person
{
public:
  int age;
  int id;
  person(int age, int id)
  {
    this->age = age;
    this->id = id;
  }
};
class hand
{
public:
  int m;
  int n;
};
//  int operator+(person &p, hand &h)
// {
//   return p.age + h.n;
// }
// person operator+(person &p, hand &h)
// {

//   return temp(p.age + h.m, h.n);
// }
class pen
{
public:
  int len;
  int price;
  pen(int len, int price)
  {
    this->len = len;
    this->price = price;
  }
  pen operator-(pen &p)
  {
    pen tmp(this->len - p.len, this->price - p.price);
    return tmp;
  }
};
int operator+(pen &p, int k)
{
  return p.len + k;
}
class hako
{
public:
  int len;
  hako(int len)
  {
    this->len = len;
  }
};
void operator<<(ostream &out, hako &h)
{
  cout << h.len << endl;
}
class mi
{
public:
  string name;
  int len;
  mi(string name, int len)
  {
    this->name = name;
    this->len = len;
  }
  mi(){
    this->name = "";
    this->len = 0;
  }
};
ostream &operator<<(ostream &out, const mi &m)
{
  cout << m.name << m.len << endl;
  return out;
}
istream& operator>>(istream &in, mi &m)
{
  in >> m.name;
  in >> m.len;
  return in;
}
int main()
{
  mi m;
  cin >> m;
  cout<< m;
  return 0;
} */

/* #include <iostream>
using namespace std;
class a
{
public:
  int len;
  char *name;
  a(int len, const char *name)
  {
    this->len = len;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
  }
  a(const a &c1)
  {
    this->len = c1.len;
    this->name = new char[strlen(c1.name) + 1];
    strcpy(this->name, c1.name);
  }
  ~a()
  {
    if (this->name != nullptr)
    {
      delete[] name;
      name = NULL;
    }
  }
  a &operator=(const a &c1)
  {
    // 1.由于不能确定this指针指向的空间是否能装下stu中的数据，所以先释放空间；
    if (this->name != nullptr)
    {
      delete[] this->name;
      this->name = nullptr;
      // 2.申请堆区空间，大小有stu决定；
      this->name = new char[strlen(c1.name) + 1];
      // 拷贝数据
      strcpy(this->name, c1.name);
      // 返回对象本身,解引用this，返回本身；
    }
    return *this;
  }
  void print()
  {
    cout << this->name << this->len << endl;
  }
};
int main()
{
  a c1(21, "xiao");
  a c2(31, "五");
  c1.print();
  c2.print();
  c1 = c2;
  a c3(41, "69岁老同志");
  c3 = c2 = c1;
  c3.print();
  c2.print();
  c1.print();
  // a c3 = c2;
  return 0;
} */
/* #include <bits/stdc++.h>
using namespace std;
const int N(110);
int dist[N];
int w[N][N];
bool st[N];
int n;
 int prim()
{
 int res = 0;
 // 初始距离为正无穷；
 memset(dist, 0x3f, sizeof(dist));
 // 1号点距离是0；
 dist[1] = 0;

 for (int i = 0; i < n; i++)
 {
   // 权值最小顶点的编号；
   int t = -1;
   for (int j = 1; j <= n; j++)
   {
     if (!st[j] && (t == -1 || dist[t] > dist[j]))
       t = j;
   }
   res += dist[t];
   st[t] = true;
   for (int j = 1; j <= n; j++)
     dist[j] = min(dist[j], w[t][j]);
 }
 return res;
}

int prim()
{
  memset(dist, 0x3f, sizeof(dist));
  int res = 0;
  dist[1] = 0;
  for (int i = 0; i < n; i++)
  {
    int t = -1;
    for (int j = 1; j <= n; j++)
    {
      if (!st[j] && (t == -1 || dist[t] > dist[j]))
        t = j;
    }
    res += dist[t];
    st[t] = true;
    for (int j = 1; j <= n; j++)
    {
      dist[j] = min(dist[j], w[t][j]);
    }
  }
  return res;
}
int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
      cin >> w[i][j];
  }
  cout << prim() << endl;
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
const int N(1e2+3);
struct edge
{
  int u, v, w;
  bool operator<(edge &u) const
  {
    return w < u.w;
  }
};
int n, m;
int fa[N];
vector<edge> edges;
void init()
{
  for (int i = 1; i <= n; i++)
    fa[i] = i;
}
int find(int x)
{
  if (fa[x] != x)
    fa[x] = find(fa[x]);
  return fa[x];
}

bool unionset(int x, int y)
{
  x = find(x), y = find(y);
  if (x == y)
    return false;
  fa[x] = y;
  return true;
}
int kluskal()
{
  sort(edges.begin(), edges.end());
  int ans = 0;
  for (int i = 1; i <= m; i++)
  {
    int u = edges[i].u;
    int v = edges[i].v;
    if (unionset(u, v))
    {
      ans += edges[i].w;
    }
  }
  return ans;
}
int main()
{
  cin >> n >> m;
  edges.resize(m + 1);
  init();
  int tot = 0;
  for (int i = 0; i < m; i++)
  {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
    tot += edges[i].w;
  }
  cout << tot - kluskal() << endl;
  return 0;
} */

/* #include <iostream>
using namespace std;
class Maker
{
  friend ostream &operator<<(ostream &out, const Maker &m);

public:
  Maker(int a)
  {
    this->a = a;
  }

  // 重载前自增
  Maker &operator++()
  {
    ++this->a;
    return *this;
  }
  // 后自增
  Maker operator++(int) // 占位参数，必须为int；
  {
    Maker tmp(*this); //*this为a=2；
    ++this->a;        // a=3;
    return tmp;
  }

private:
  int a;
};
ostream &operator<<(ostream &out, const Maker &m)
{
  cout << m.a;
  return out;
}
void test()
{
  Maker m(1);
  cout << m << endl;
  cout << ++m << endl;
  cout << m++ << endl;
  cout << m << endl;
}
int main()
{
  test();

  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
class Mystring
{
  friend ostream &operator<<(ostream &out, Mystring &str);
  friend istream &operator>>(istream &in, const Mystring &str);

public:
  Mystring()
  {
  }
  Mystring(int n, char ch)
  {
  }
  Mystring(const Mystring &str)
  {
  }
  Mystring &operator=(const Mystring &str)
  {
  }
  Mystring operator+(const Mystring &str)
  {
  }
  Mystring operator+(const Mystring &str)
  {
  }
  Mystring operator+(const char *str)
  {
  }
  Mystring operator+=(const Mystring &str)
  {
  }
  int getsize()
  {
  }
  char &operator[](int index)
  {
  }
  Mystring(const char *string)
  {
  }
  ~Mystring()
  {
  }

private:
  char *pstr;
  int len;
};
void test()
{
}
int main()
{

  return 0;
} */

/* #include <iostream>
#include <vector>
using namespace std;
// 循环链表节点类
class ListNode
{
public:
  int value;      // 节点的值（密码）
  ListNode *next; // 指向下一个节点的指针
  // 构造函数，初始化节点
  ListNode(int val)
  {
    value = val;
    next = NULL;
  }
};

// 循环链表类
class JosephCurcular
{
private:
  ListNode *head; // 链表的头节点指针

public:
  // 构造函数，初始化链表
  JosephCurcular()
  {
    head = NULL;
  }
  // 创建循环链表并设置密码值
  void createLinkedList(int n, vector<int> &passwords)
  {
    if (n <= 0)
      return;

    // 创建链表的头节点
    head = new ListNode(1);
    ListNode *current = head;

    // 创建剩余的节点，并将其连接到链表中
    for (int i = 1; i < n; i++)
    {
      ListNode *newNode = new ListNode(i + 1);
      current->next = newNode;
      current = current->next;
    }

    // 将链表首尾相连，形成循环链表
    current->next = head;

    // 设置每个节点的密码值
    current = head;
    for (int i = 0; i < n; i++)
    {
      current->value = passwords[i];
      current = current->next;
    }
  }

  // 根据报数规则找到出列顺序并返回
  vector<int> getOrder(int m)
  {
    vector<int> ans;
    if (head == NULL)
      return ans;
    ListNode *current = head;
    ListNode *prev = NULL;
    int count = 0;

    // 循环直到链表中只剩下一个节点
    while (current->next != current)
    {
      count++;
      // 当报数达到上限m时，将当前节点从链表中删除，并将其密码添加到顺序中
      if (count == m)
      {
        ans.push_back(current->value);
        // 迭代、更新链表的连接关系，删除出列的节点
        if (prev == NULL)
        {
          prev = current;
          while (prev->next != current)
            prev = prev->next;
        }
        prev->next = current->next;
        ListNode *temp = current;
        current = current->next;
        // 销毁节点，释放内存；
        delete temp;
        count = 0;
      }
      else
      {
        prev = current;
        current = current->next;
      }
    }
    // 添加最后一个出列的人的密码到顺序中
    ans.push_back(current->value);
    delete current;
    head = NULL;
    return ans;
  }
};

int main()
{

  cout << "----Joseph环游戏开始，请根据提示输入！----" << endl;
  int n; // 总人数
  int m; // 初始报数上限值

  cout << "请输入总人数n：";
  cin >> n;
  if (n <= 0)
  {
    cout << "----错误输入：应输入一个大于等于1的数----" << endl;
    cout << "请重新输入n：" << endl;
    cin >> n;
  }
  cout << "请输入初始报数上限值m：";
  cin >> m;
  if (m <= 0)
  {
    cout << "----错误输入：应输入一个大于等于1的数----" << endl;
    cout << "请重新输入m：" << endl;
    cin >> m;
  }
  vector<int> passwords(n); // 存储每个人的密码
  cout << "请输入每个人的密码（正整数）：" << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> passwords[i];
  }
  // 创建JosephCurcular类，调用无参构造；
  JosephCurcular linklist;
  // 初始化 linklist的成员变量，调用createLinkedlist函数；
  linklist.createLinkedList(n, passwords);
  vector<int> ans = linklist.getOrder(m);
  cout << "出列顺序：";
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  cout << "----游戏结束----" << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
class Father
{
public:
  Father()
  {
    a = 10;
  }
  void f(int a){
    this->a = a;
  }
  int a;
  static int fun(){
    cout << "static void f" << endl;
    return 0;
  }
};
class son : public Father
{
public:
  int a;
  son()
  {
    a = 20;
  }
  void f(){
    this->a = 111;
  }
  void fun(){
    cout << "son f" << endl;
  }
};
int main()
{
  son s;
  s.fun();
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
struct edge
{
  int v, w;
  edge(int _v, int _w)
  {
    v = _v;
    w = _w;
  }
};
const int maxn(5e3 + 3);
int n;
vector<edge> edges[maxn];
int dis[maxn];
set<pair<int, int>> q;
void dijkstra(int s, int t)
{
  memset(dis, 127, sizeof(dis));
  dis[s] = 0;
  q.clear();
  for (int i = 1; i <= n; i++)
  {
    q.insert({dis[i], i});
  }
  for (; !q.empty();)
  {
    int u = q.begin()->second;
    if (u == t || dis[u] > 1<<30)
    {
      break;
    }
    q.erase(q.begin());
    for (auto i : edges[u])
    {
      if (dis[i.v] > dis[u] + i.w)
      {
        q.erase({dis[i.v], i.v});
        dis[i.v] = dis[u] + i.w;
        q.insert({dis[i.v], i.v});
      }
    }
  }
}
int m, s;
int main()
{
  cin >> n >> m >> s;
  for (int i = 1; i <= m; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    edges[x].push_back(edge(y, z));
  }
  dijkstra(s, n);
  for (int i = 1; i <= n; i++)
    cout << dis[i] << ' ';
  return 0;
}

 */

/* #include <bits/stdc++.h>
using namespace std;
struct edge
{
  int v, w;edge(int v,int w){
    this->v = v;
    this->w = w;
  }
};
struct node
{
  int dis, u;

  bool operator>(const node &a) const { return dis > a.dis; }
};
const int maxn(1e5 + 3);
vector<edge> edges[maxn];
int dis[maxn], vis[maxn];
priority_queue<node, vector<node>, greater<node>> q;

void dijkstra(int s,int t)
{
  memset(dis, 63, sizeof(dis));
  dis[s] = 0;
  q.push({0, s});
  while (!q.empty())
  {
    int u = q.top().u;
    q.pop();
    if (vis[u])
      continue;
    vis[u] = 1;
    for (auto ed : edges[u])
    {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w)
      {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
}



struct status{
  int u;
  int dis;
  status(int u,int dis){
    this->u = u;
    this->dis = dis;
  }
};


int n, m, s;
int main()
{
  cin >> n >> m >> s;
  for (int i = 1; i <= m; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    edges[x].push_back(edge(y, z));
  }
  dijkstra(s, n);
  for (int i = 1; i <= n; i++)
    cout << dis[i] << ' ';
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
class base{
  public:
    int u;
    int id;
};
class base2{
  public:
    int g;
    int m;
};
class son1:public base{

    ;
};
class son2:public base{
};


int
main()
{

    return 0;
}
 */
/* #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
      cin >> h[i];
    }
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
      if (h[i] > h[i - 1])
      {
        dp[i] = dp[i - 1] + 1;
      }
      else
      {
        dp[i] = dp[i - 1];
      }
    }
    cout << dp[n - 1] << endl;
    return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
stack<char> sa;
int n;
const int N(1e5 + 3);
char s[N];
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i];
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '(')
    {
      sa.push(s[i]);
    }
    if (s[i] == ')')
    {
      if (sa.top() != '(')
      {
        cout << "NO";
        return 0;
      }
      else
      {
        sa.pop();
      }
    }
  }
  if (!sa.empty())
  {
    cout << "NO" << endl;
    return 0;
  }
  else
    cout << "YES" << endl;
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
stack<char> sa;
int n;
const int N(1e5 + 3);
char s[N];
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i];
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '(')
    {
      sa.push(s[i]);
    }
    if (s[i] == ')')
    {
      if (sa.empty())
      {
        cout << "NO" << endl;
        return 0;
      }
      else if (sa.top() == ')')
      {
        sa.pop();
      }
      else
      {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  if (sa.empty())
  {
    cout << "YES" << endl;
  }
  else
    cout << "NO" << endl;
  return 0;
} */
/*
 #include <iostream>
using namespace std;
typedef struct ListNode
{
  int val;
  ListNode *next;
  ListNode()
  {
    val = 0;
    next = nullptr;
  }
} ListNode;
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
  ListNode *dummy = new ListNode;
  ListNode *cur = dummy;
  while (l1 != NULL && l2 != NULL)
  {
    if (l1->val < l2->val)
    {
      cur->next = l1;
      l1 = l1->next;
    }
    else
    {
      cur->next = l2;
      l2 = l2->next;
    }
    cur = cur->next;
  }
  if (l1 != NULL)
  {
    cur->next = l1;
  }
  else
  {
    cur->next = l2;
  }
  return dummy->next;
}
int main()
{
  ListNode *l1 = new ListNode;
  ListNode *l2 = new ListNode;
  ListNode *p = l1;
  ListNode *q = l2;
  int a;
  for (int i = 0; i < 15; i++)
  {
    cin >> a;
    p->next = new ListNode;
    p->val = a;
    p = p->next;
  }
  for (int i = 0; i < 15; i++)
  {
    cin >> a;
    q->next = new ListNode;
    q->val = a;
    q = q->next;
  }
  ListNode *result = mergeTwoLists(l1->next, l2->next);
  while (result != NULL)
  {
    cout << result->val << " ";
    result = result->next;
  }
  return 0;
}
 */
/* #include <iostream>
#include <stack>
using namespace std;
int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  stack<char> st;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '(')
    {
      st.push(s[i]);
    }
    else
    {
      if (st.empty())
      {
        cout << "NO" << endl;
        return 0;
      }
      else
      {
        st.pop();
      }
    }
  }
  if (st.empty())
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  return 0;
}

 */

/* #include <bits/stdc++.h>
using namespace std;
vector<int> a(30);
int j = 0;
typedef struct ListNode
{
  int val;
  ListNode *next;
  ListNode()
  {
    val = 0;
    next = nullptr;
  }
} ListNode;
void createList(ListNode *head)
{
  ListNode *curr = head;
  for (int i = 1; i <= 15; i++)
  {
    cin >> curr->val;
    a[j] = curr->val;
    j++;
    ListNode *r = nullptr;
    r = new ListNode;
    curr->next = r;
    curr = r;
  }

}
ListNode *merge(ListNode *list1, ListNode *list2)
{
  ListNode *dummy = new ListNode;
  ListNode *curr = dummy;
  while (list1 && list2)
  {
    if (list1->val <= list2->val)
    {

      curr->next = list1;
      list1 = list1->next;
    }
    else
    {
      curr->next = list2;
      list2 = list2->next;
    }
    curr = curr->next;
  }
  curr->next = list1 == NULL ? list2 : list1;
  return dummy->next;
}
vector<int> ans;
int main()
{
  ListNode *head1, *head2;
  head1 = new ListNode;
  head2 = new ListNode;
  createList(head1);
  createList(head2);
  ListNode *head3 = merge(head1, head2);
  ListNode *curr = head3, *prev = head3;
  sort(a.begin(), a.end());
  for(auto i:a)
    cout << i << " ";
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
string s;
int main()
{

  stack<int> sta1, sta2;
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++)
  {
    if (s[i] >= '0' && s[i] <= '9')
      sta1.push(s[i]);
      if(s[i]=='+'){
        if(sta2.top()=='*'){
          int x = sta1.top();
          sta1.pop();
          int y = sta1.top();
          sta1.pop();
          sta1.push(x * y);
          sta2.push(s[i]);
        }
      }
      if(s[i]=='*')
      {
        sta2.push(s[i]);
      }
  }
  int ans = 0;
  while(!sta1.empty()){
      ans += sta1.top();
      sta1.pop();
  }
  cout << ans;
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ans;
bool cmp(int a, int b)
{
  return a > b;
}
int main()
{
  cin >> n;
  ans.resize(n);
  for (int i = 0; i < n; i++)
    cin >> ans[i];
  sort(ans.begin(), ans.end(), cmp);
  for (auto i : ans)
  {
    cout << i << ' ';
  }
} */

/* #include <bits/stdc++.h>
using namespace std;
vector<int> a(30);
int j = 0;
typedef struct ListNode
{
  int val;
  ListNode *next;
  ListNode()
  {
    val = 0;
    next = nullptr;
  }
} ListNode;
void createList(ListNode *head)
{
  ListNode *curr = head;
  for (int i = 1; i <= 15; i++)
  {
    cin >> curr->val;
    a[j] = curr->val;
    j++;
    ListNode *r = nullptr;
    r = new ListNode;
    curr->next = r;
    curr = r;
  }
}
ListNode *merge(ListNode *list1, ListNode *list2)
{
  ListNode *dummy = new ListNode;
  ListNode *curr = dummy;
  while (list1 && list2)
  {
    if (list1->val <= list2->val)
    {

      curr->next = list1;
      list1 = list1->next;
    }
    else
    {
      curr->next = list2;
      list2 = list2->next;
    }
    curr = curr->next;
  }
  curr->next = list1 == NULL ? list2 : list1;
  return dummy->next;
}
vector<int> ans;
int main()
{
  ListNode *head1, *head2;
  head1 = new ListNode;
  head2 = new ListNode;
  createList(head1);
  createList(head2);
  ListNode *head3 = merge(head1, head2);
  ListNode *curr = head3, *prev = head3;
  while (head3 != nullptr)
  {
    cout << head3->val << " ";
    head3 = head3->next;
  }
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
class animal
{
public:
  virtual void f()
  {
    cout << " animal" << endl;
  }
};
class dog1 : public animal
{
public:
  virtual void f()
  {
    cout << " dog1" << endl;
  }
};
class dog : public animal
{
public:
  virtual void f()
  {
    cout << " dog" << endl;
  }
};
class dog2 : public animal
{
public:
  virtual void f()
  {
    cout << " dog2" << endl;
  }
};
void test(animal *ani)
{
  ani->f();
}
void test2()
{
  dog *d = new dog;
  test(d);
  dog1 *d1 = new dog1;
  test(d1);
}
void test3(){
  dog2 *d2 = new dog2;
  test(d2);
}
int main()
{
  test2();
  test3();
  return 0;
}
 */

/* #include <bits/stdc++.h>
using namespace std;
int n;
const int N(1e3);
int a[N];
void insertsort(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int t = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] < t)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = t;
  }
}
void shell_sort(int arr[], int n)
{
  for (int gap = n / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < n; i++)
    {
      int t = arr[i];
      int j = i - gap;
      while (j >= 0 && arr[j] > t)
      {
        arr[j + gap] = arr[j];
        j -= gap;
      }
      arr[j + gap] = t;
    }
  }
}

//
void heapify(int arr[], int n, int i)
{
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < n && arr[l] > arr[largest])
  {
    largest = l;
  }
  if (r < n && arr[r] > arr[largest])
  {
    largest = r;
  }
  if (largest != i)
  {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapsort(int arr[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }
  for (int i = n - 1; i >= 0; i--)
  {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main()
{
  int a[] = {1, 0, -2, 1, 2, 11, 2, 3, 55, 4};
  // insertsort(a,10);
  //shell_sort(a, 10);
  heapsort(a, 10);
  for (int i = 0; i < 10; i++)
  {
    cout << a[i] << ' ';
  }
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(1e8 + 2);
bool a[N];
int n;
void is_prime1()
{
  memset(a, true, sizeof(a));
  a[0] = false;
  a[1] = false;
  int p = 2;
  while (p * p <= n)
  {
    if (a[p] == true)
    {
      for (int i = p * p; i <= n; i += p)
      {
        a[i] = false;
      }
    }
    p++;
  }
}
std::vector<bool> is_prime;
std::vector<int> primes;
void euler_sieve(int n)
{
  is_prime.resize(n + 1, true);
  for (int i = 2; i <= n; ++i)
  {
    if (is_prime[i])
    {
      primes.push_back(i);
    }
    for (int j = 0; j < primes.size() && i * primes[j] <= n; ++j)
    {
      is_prime[i * primes[j]] = false;
      if (i % primes[j] == 0)
      {
        break;
      }
    }
  }
}
int main()
{
  scanf("%d", &n);
  // s_prime();
  euler_sieve(n);
  int ans = 0;
  cout << is_prime.size() << endl;
  for (int i = 2; i < n + 1; i++)
  {
    if (is_prime[i] == true)
      cout << i << ' ';
  }
  //printf("%d\n", ans);
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
class animal
{
public:
  virtual void speak() = 0;
};
class dog : public animal
{
public:
  virtual void speak()
  {
    cout << "汪汪" << endl;
  }
  dog(string name)
  {
    this->name = name;
  }

private:
  string name;
};

class dark : public animal
{
public:
  virtual void speak()
  {
    cout << "嘎嘎" << endl;
  }
  dark(string name)
  {
    this->name = name;
  }

private:
  string name;
};
class tiger : public animal
{
public:
  virtual void speak()
  {
    cout << "aoao" << endl;
  }
  tiger(string name)
  {
    this->name = name;
  }

private:
  string name;
};
class zoo
{

public:
  zoo()
  {
    mcapacity = 1024;
    msize = 0;
    this->p = new animal *[mcapacity];
  }
  int addanimal(animal *ani)
  {
    if (mcapacity == msize)
    {
      return -1;
    }
    this->p[msize] = ani;
    msize++;
    return 0;
  }
  void jiao(){
    for (int i = 0; i < msize;i++){
      this->p[i]->speak();
    }
  }
private:
  animal **p;
  int mcapacity;
  int msize;
};
class cat:public animal {
  public:
  virtual void speak(){

  }
}
void test()
{
  // 创建动物园
  zoo *z = new zoo;
  z->addanimal(new dog("xiaowang"));
  z->addanimal(new dark("xiangyezi"));
  z->addanimal(new tiger("laofu"));
  z->jiao();
}
int main()
{
  // test();
  test();
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
template <class T>
void myswap(T &a, T &b)
{
  T c;
  c = a;
  a = b;
  b = c;
}
void test()
{

  float a = 0.21;
  float b = 33.987654;
  myswap(a, b);
  cout << a << endl;
}

template <typename T>
void ds(T &a)
{
  cout << ' ' << endl;
}

template <typename T>
/* void ws(vector<T> &a)
{
  sort(a.begin(), a.end());
}
 */
/*
#include <bits/stdc++.h>
using namespace std;

int exgcd(int a,int b,int &x,int &y){
  if(!b){
    x = 1;
    y = 0;
    return a;
  }
  int d = exgcd(b, a % b, x, y);
  int t = x;
  x = y;
  y = t - (a / b) * y;
  return d;
}
int main()
{
  int a, b;
  cin >> a >> b;
  int x, y;
  int d=exgcd(a, b, x, y);
  cout << (x + b) % b;
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
long long exgcd(long long a, long long b, long long &x, long long &y)
{
  if (!b)
  {
    x = 1;
    y = 0;
    return a;
  }
  int d = exgcd(b, a % b, x, y);
  int t = x;
  x = y;
  y = t - (a / b) * y;
  return d;
}
int main()
{
  long long x, y, n, m, l;
  cin >> x >> y >> m >> n >> l;
  long long a = x - y;
  long long b = n - m;
  if (b < 0)
  {
    b = -b;
    a = -a;
  }
  long long x1, y1;
  long long d = exgcd(b, l, x1, y1);
  cout << x1 << endl;
  x1 = (x1 * (a / d));
  if (a % d != 0)
  {
    cout << "Impossible";
  }
  else
  {
    cout << (x1 % (l / d) + (l / d)) % (l / d);
  }
  return 0;
}
 */

/*
#include <bits/stdc++.h>
using namespace std;
int exgcd(int a, int b, int &x, int &y)
{
  if (!b)
  {
    x = 1;
    y = 0;
    return a;
  }
  int d = exgcd(b, a % b, x, y);
  int t = x;
  x = y;
  y = t - (a / b) * y;
  return d;
}
int main()
{
  int a, b; // b=1;
  cin >> a >> b;
  int x, y;
  int d = exgcd(a,b, x, y);
  int s = x * (1 / d);
  int t = (b / d);
  cout << (s % t + t) % t<< endl;
  return 0;
}  */

/* #include <bits/stdc++.h>
using namespace std;
const int N(1e5);
char s[N], p[N];
int nxt[N];
int z[N];
void exkmp()
{
  int l = 1, r = 0;
  z[1] = 0;
  int n = strlen(s + 1);
  for (int i = 2; i <= n; i++)
  {
    if (i > r)
      z[i] = 0;
    else
    {
      int k = i - l + 1;
      z[i] = min(z[k], r - i + 1);
    }
    while (i + z[i] <= n && s[z[i] + 1] == s[z[i] + i])
      ++z[i];
    if (i + z[i] - 1 > r)
    {
      l = i;
      r = i + z[i] - 1;
    }
  }
  int ans = 0, x = 0;
  for (int i = 1; i <= n; i++)
  {
    if (i + z[i] - 1 == n)
    {
      if (x >= z[i])
        ans = max(ans, z[i]);
    }
    x = max(x, z[i]);
  }
  if(!ans){
    cout << "";
  }
  else{
    for (int i = 1; i <= ans;i++)
      cout << s[i];
  }
}
int main()
{
  cin >> s + 1;
  exkmp();
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
const int N(1e8);
int p[N];
char s[N], t[N];
void manacher()
{
  int n = strlen(s + 1);
  int m = 0;
  t[n + 1] = '$';
  for (int i = 1; i <= n; i++)
  {
    t[++m] = s[i];
    t[++m] = '$';
  }
  m = 0;
 int r = 0;
  for (int i = 1; i <= m; i++)
  {
    // 无法匹配，从当前位置开始暴力匹配
    if (i > r)
    {
      p[i] = 1;
    } // 往两边扩展找到最大的回文半径；
    else
    {
      p[i] = min(p[2 * m - i], r - i + 1);
    }
    // 暴力匹配
    while (i - p[i] > 0 && i + p[i] <= m && t[i - p[i]] == t[i + p[i]])
      ++p[i];
    // 更新l，r
    if (i + p[i] - 1 > r)
    {
      m = i;
      r = i + p[i] - 1;
    }
    int ans = 0;
    //找到最大的回文半径
    for (int i = 1; i <= m; i++)
    {
      ans = max(ans, p[i]);
    }
    //减一为原串的回文半径；
    cout << ans - 1 << endl;
  }
}
int main()
{
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
void bs(int *a, int target, int l, int r)
{
 int m = 0;
 while (l <= r)
 {
   m = l + ((r - l) >> 1);
   if (target < a[m])
     r = m - 1;
   else if (target > a[m])
     l = m + 1;
   else
   {
     break;
   }
  }
  cout << "m= " << m << ' ' << " l= " << l << endl;
}
void bs2(int *a, int target, int l, int r)
{
 int m = 0;
 //取不到r，则r=l没有意义；
 while (l < r)
 {
   m = l + ((r - l >> 1));
   if (target < a[m])//r取不到m这个值，故更新为m即可
     r = m;
   else if (target > a[m])//l是可取值的
     l = m + 1;
   else
     break;
 }
 cout << "m= " << m << ' ' << " r= " << r<< endl;
}
int main()
{
 int a[] = {1, 5, 7, 9, 22, 76, 113, 234, 456};
 bs(a, 7, 0, 8);
 bs(a, 8, 0, 8);
 bs2(a, 100, 0, 8);
 return 0;
}

 */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(2e5 + 2);
int a[] = {1, 5, 7, 9, 22, 76, 113, 234, 456};
// 向左找：大于结果的最小值
// 右找：小于结果的最大值

// 与STL中的Lower_bound效果相同--向左找：大于结果的最小值
void bs(int l, int r, int x)
{
  int m = 0;
  while (l < r)
  {
    m = l + r >> 1;
    if (a[m] >= x)
      r = m;
    else
      l = m + 1;
  }
  cout << "m= " << m << ' ' << " l= " << l << "r= " << r << endl;
}
void bs2(int l, int r, int x)
{
  int m = 0;
  while (l < r)
  {
    m = r + l + 1 >> 1;
    if (a[m] <= x)
      l = m;
    else
      r = m - 1;
  }
  cout << "m= " << m << ' ' << "l= " << l << " r= " << r << endl;
}
int main()
{
  // int a[] = {1, 5, 7, 9, 22, 76, 113, 234, 456};
  vector<int> arr(a, a + 9);
  bs(0, 8, 7);
  bs2(0, 8, 20);
  cout << *(lower_bound(arr.begin(), arr.end(), 80)) << endl;
  bs(0, 8, 80);
  bs2(0, 8, 80);
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N(1e5 + 10);
int a[N];
int main()
{
  cin >> n >> m;
  int sum;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + n + 1);
  a[0] = -2e9;
  a[n + 1] = 2e9;
  while (m--)
  {
    int x;
    cin >> x;
    int l = 1, r = n;
    while (l < r)
    {
      int m = r + l >> 1;
      if (a[m] >= x)
        r = m;
      else
        l = m + 1;
    }
    if (a[l] - x <= x - a[l - 1])
      sum += a[l] - x;
    else
      sum += x - a[l - 1];
  }
  cout << sum << endl;
  return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int  a[N], x, sum, n, m;

int main()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + n + 1); // 排序勿忘
  a[0] = -1e9;
  a[n + 1] = 1e9; // 最后再解释

  while (m--)
  {
    cin >> x;
    int t = lower_bound(a + 1, a + n + 1, x) - a; // 如果分数线都比估分低，那返回的位置是n+1，否则返回第一个大于等于估分的位置。
    if (a[t] - x <= x - a[t - 1])
      sum += a[t] - x;
    else
      sum += x - a[t - 1];
  }
  cout << sum;
  return 0;
  // a[0]=-1e12: 所有分数先可能都比估分大，那么l就为1，n-1就为0，故设a[0]为无穷小，则第一个值就为解
  // a[n+1]=1e12: 所有分数线可能都比估分小，那么l就为n,a[l]-x可能为负，则设a[n+1]为无穷大，
  // 并将r设为n+1，如此，l最大为n+1，则最后一个就为解
}
 */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(1e5 + 10);
int a[N];
int n, k;
int sum = 0;
int max_l;

bool check(int m)
{
  int sum = 0;
  for (int i = 1; i <= n; i++)
  {
    sum += a[i] / m;
  }
  //在m的长度下，割的段数大于给定值，则割小了，需要往大了割；
  if (sum >= k)
    return true;
  else
    return false;
}
int main()
{
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    sum += a[i];
    if (a[i] > max_l)
      max_l = a[i];
  }
  if (sum < k)
  {
    cout << 0 << endl;
    return 0;
  }
  int l = 0, r = sum;
  while (l < r)
  {
    int m = l + r + 1 >> 1;
    //割小了，m是小于答案的
    if (check(m))
      l = m;
    else
      r = m - 1;
  }
  cout << l << endl;
  return 0;
} */

/* 
#include <bits/stdc++.h>
using namespace std;
const int N(1e5 + 10);
int n, len, m;
int a[N];
bool check(int x)
{
  int tot = 0;
  int now = 0;
  int i = 0, r = n + 1;
  while (i < r)
  {
    i++;
    if (a[i] - a[now] < x)
      tot++;
    else
      now = i;
  }
  if (tot <= m)
    return true;
  else
    return false;
}
int main()
{
  cin >> len >> n >> m;

  int r = len;
  a[0] = 0, a[n + 1] = len;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  int l = 1;
  while (l < r)
  {
    int m = l + r + 1 >> 1;
    if (check(m))
      l = m;
    else
      r = m - 1;
  }
  cout << l << endl;
  return 0;
} */