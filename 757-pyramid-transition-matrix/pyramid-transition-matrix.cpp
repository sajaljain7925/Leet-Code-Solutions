class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

    bool dfs(string curr) {
        if (curr.size() == 1) return true;
        if (memo.count(curr)) return memo[curr];

        vector<string> nextRows;
        buildNext(curr, 0, "", nextRows);

        for (string &next : nextRows) {
            if (dfs(next)) {
                memo[curr] = true;
                return true;
            }
        }

        memo[curr] = false;
        return false;
    }

    void buildNext(string &curr, int idx, string path, vector<string> &res) {
        if (idx == curr.size() - 1) {
            res.push_back(path);
            return;
        }

        string key = curr.substr(idx, 2);
        if (!mp.count(key)) return;

        for (char c : mp[key]) {
            buildNext(curr, idx + 1, path + c, res);
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return dfs(bottom);
    }
};
