#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

const int MAXV = 100;
const int INF = 100000000;
int n;
char s;

struct Edge{
	char u,v;
	int distance;
};
vector<Edge> edge;
map<char,int> d;
set<char> G;
map<char,char> pre;

bool Bellman_ford(char s)
{
	for(char c='a';c<='z';c++)
	{
		d[c] = INF;
	}
	d[s] = 0;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=0;j<edge.size();j++)
		{
			if(d[edge[j].u] + edge[j].distance < d[edge[j].v])
			{
				d[edge[j].v] = d[edge[j].u] + edge[j].distance;
				pre[edge[j].v] = edge[j].u;
			}
		}
	}
	for(int i=0;i<edge.size();i++)
	{
		if(d[edge[i].v] > d[edge[i].u] + edge[i].distance)
		{
			return false;
		}
	}
	return true;
}


void print_path(char root) //��ӡ���·��·��������  
{  
	int cnt = 0;
	int path[MAXV];
    while(root != pre[root]) //ǰ��  
    {  
    	path[cnt++] = root; 
        root = pre[root];  
    }  
    reverse(path, path + cnt);
    for(int i=0;i<cnt;i++)
    {
    	if(i != cnt-1)
	    {
	    	printf("%c-",path[i]);
		}	
		else
		{
			printf("%c",path[i]);
		}
	}
}  
int main()
{
	freopen("./bf.in","r",stdin); //�����ض����൱�����ڿ���̨����������in�ļ�������������� 
//	freopen("./bf.out","w",stdout);	 //����ض����൱�����ڿ���̨��������ȫ���ĳ����뵽���out�ļ����� 
	cin>>n>>s;
	
	for(int i=0;i<n;i++)
	{
		Edge t;
		char u,v;
		cin>>u>>v>>t.distance;
		t.u = u;
		t.v = v;
		G.insert(u);
		G.insert(v);
		edge.push_back(t);
	}
	
	if(Bellman_ford(s))
	{
		for(set<char>::iterator it = G.begin();it!=G.end();it++)
		{
			print_path(*it);
			cout<<" "<<d[*it]<<endl;
		}
	}
	return 0;
}
