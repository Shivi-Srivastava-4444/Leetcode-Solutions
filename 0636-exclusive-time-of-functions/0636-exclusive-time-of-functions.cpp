class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        stack<int> st;
        int prev = 0;

        for (auto& log : logs) {
            int p = log.find(':');
            int id = stoi(log.substr(0, p));
            int q = log.find(':', p + 1);
            string type = log.substr(p + 1, q - p - 1);
            int time = stoi(log.substr(q + 1));

            if (type == "start") {
                if (!st.empty()) ans[st.top()] += time - prev;
                st.push(id);
                prev = time;
            } else {
                ans[st.top()] += time - prev + 1;
                st.pop();
                prev = time + 1;
            }
        }

        return ans;
    }
};