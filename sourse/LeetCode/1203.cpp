//https://leetcode-cn.com/problems/sort-items-by-groups-respecting-dependencies/
#include <vector>
#include <queue>
#include <iostream>
using namespace std;


class Solution {
public:




    static vector<int> topSort(vector<int>& deg, vector<vector<int>>& To, vector<int> items) {
        queue<int> Q;
        for (auto& item : items) {
            if (deg[item] == 0) {
                Q.push(item);
            }
        }
        vector<int> ret;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            ret.emplace_back(u);
            for (auto& v : To[u]) {
                if (--deg[v] == 0) {
                    Q.push(v);
                }
            }
        }
        return ret.size() == items.size() ? ret : vector<int>{};
    }

    struct GROUP {
        vector<int> Items;

        int Sort(int n, vector<vector<int>>& beforeItems) {

            if (Items.size() == 0) {
                return 1;
            }

            vector<int> id(n, -1);
            vector<vector<int>> To(Items.size());
            vector<int> Indeg(Items.size());
            for (int i = 0; i < Items.size(); ++i) {
                id[Items[i]] = i;
            }
            for (auto v : Items) {
                for (auto u : beforeItems[v]) {
                    if (id[u] >= 0) {
                        To[id[u]].push_back(id[v]);
                        Indeg[id[v]]++;
                    }
                }
            }

            vector<int> NO;
            for (int i = 0; i < Items.size(); ++i) {
                NO.push_back(i);
            }

            NO = topSort(Indeg, To, NO);
            if (NO.size() == 0) {
                return 0;
            }
            
            for (int i = 0; i < Items.size(); ++i) {
                NO[i] = Items[NO[i]];
            }
            Items = NO;
            return 1;

        }
    };

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

        vector<vector<int>> To(n + m);
        vector<int> Indeg(n + m);
        vector<int> gid(n);

        vector<GROUP> G(n+m);


        int cnt = m;
        for (int i = 0; i < n; ++i) {
            //构建组
            if (group[i] == -1) {
                G[cnt].Items.push_back(i);
                gid[i] = cnt;
                ++cnt;
            }
            else {
                G[group[i]].Items.push_back(i);
                gid[i] = group[i];
            }
        }

        for (int v = 0; v < n; ++v) {
            for (auto u : beforeItems[v]) {
                //组间边
                if (gid[v] != gid[u]) {
                    To[gid[u]].push_back(gid[v]);
                    Indeg[gid[v]]++;
                }
            }
        }

        vector<int> GNO;

        //组内拓扑排序
        for (int i = 0; i < cnt; ++i) {
            GNO.push_back(i);
            if (G[i].Items.size() == 0) {
                continue;
            }
            if (!G[i].Sort(n,beforeItems)) {
                return vector<int> {};
            }
        }

        //组间拓扑排序
        GNO=topSort(Indeg, To, GNO);
		if (GNO.size()!=cnt) {
			return vector<int> {};
		}

        vector<int> ret;

        for (int i = 0; i < cnt; ++i) {
            for (auto x : G[GNO[i]].Items) {
                ret.push_back(x);
            }
        }


        return ret;
    }
};

int main()
{
    vector<int> group = { 2,0,-1,3,0 };
    vector<vector<int>> before = { {2,1,3},{2,4},{},{},{} };
    Solution S;
    vector<int> ans;
    ans=S.sortItems(5, 5, group, before); 

    for (auto x : ans) {
        cout << x << endl;
    }

    return 0;
}
