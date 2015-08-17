void tarjan(int u)
{
	int v;
	dfn[u] = low[u] = ++index;
	ins[u] = true;
	s.push(u);
	for (int i = p[u]; i; i = edge[i].next)
	{
		v = edge[i].v;
		if (!dfn[v])
		{
			tarjan(v);
			if (low[j] < low[i])
				low[i] = low[j];
		}
		else if (ins[v] && dfn[v] < low[u])
			low[u] = dfs[v];
	}
	if (dfn[i] == low[i])
	{
		bcnt ++;
		do
		{
			v = s.top();
			s.pop();
			ins[v] = false;
			belong[v] = bcnt;
		}
		while(j != i);
	}
}
void solve()
{
	int i;
	bcnt = index = 0;
	memset(dfn, 0, sizeof(dfn));
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
}