private static int lca(int a, int b) {
    if (depth[a] < depth[b]) {int t = a; a = b; b = t;}
    int diff = depth[a] - depth[b];
    for (int i = 0; (1 << i) <= diff; i++)
        if (((diff) & (1 << i)) != 0)
            a = anc[i][a];

    if (a == b)
        return a;

    for (int i = LOG-1; i >= 0; i--)
        if (anc[i][a] != anc[i][b]) {
            a = anc[i][a];
            b = anc[i][b];
        }

    return anc[0][a];
    }

private static void init() {
    Arrays.fill(depth, 1 << 29);
    int front = 0, back = 0;
    depth[0] = 0;
    adepth[0] = 0;
    queue[back++] = 0;
    anc[0][0] = -1;

    while (front != back) {
        int node = queue[front++];
        for (Edge e : graph[node]) {
            if (depth[node] + 1 < depth[e.to]) {
                adepth[e.to] = adepth[node] + e.weight;
                depth[e.to] = depth[node] + 1;
                anc[0][e.to] = node;
                queue[back++] = e.to;
            }
        }
    }

    for (int k = 1; 1 << k < n; k++)
        for (int i = 0; i < n; i++)
            anc[k][i] = anc[k - 1][i] == -1 ? -1 : anc[k - 1][anc[k - 1][i]];
    }