void spfa(int n,int s)
{
	for(int i = 1 ; i <= n ; i++)
		dis[i] = INF;
	dis[s] = 0;
	vis[s] = 1;
	q.push(s);
	while(q.empty())
	{
		k = q.front();
		q.pop();
		for(int i = p[t] ; i ; i = edge[i].next)
		{
			int v = edge[i].to;
			int w = edge[i].w;
			if(dis[v] + w > dis[t])
			{
				dis[t] = dis[v] + w;
				q.push(i);
				vis[i] = true;
				vis[s] = false;
			}
		}
	}
}