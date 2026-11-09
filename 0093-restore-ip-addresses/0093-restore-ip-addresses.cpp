class Solution {
public:
    vector<string> ans;

    void solve(string& s, int pos, int parts, string ip) {
        if (parts == 4) {
            if (pos == s.size())
                ans.push_back(ip);
            return;
        }

        for (int len = 1; len <= 3 && pos + len <= s.size(); len++) {
            if (len > 1 && s[pos] == '0') break;

            string part = s.substr(pos, len);
            if (stoi(part) > 255) break;

            solve(s, pos + len, parts + 1,
                  ip + part + (parts == 3 ? "" : "."));
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        if (s.size() < 4 || s.size() > 12) return ans;

        solve(s, 0, 0, "");
        return ans;
    }
};