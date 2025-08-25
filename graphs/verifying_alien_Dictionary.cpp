// class Solution {
// public:
//     bool isAlienSorted(vector<string>& words, string order) {
//         vector<int> rank(26);
//         for (int i = 0; i < order.size(); ++i) {
//             rank[order[i] - 'a'] = i;
//         }

//         for (int i = 0; i < words.size() - 1; ++i) {
//             string& w1 = words[i];
//             string& w2 = words[i + 1];
//             bool valid = false;

//             for (int j = 0; j < min(w1.size(), w2.size()); ++j) {
//                 int r1 = rank[w1[j] - 'a'];
//                 int r2 = rank[w2[j] - 'a'];

//                 if (r1 < r2) {
//                     valid = true;
//                     break;
//                 } else if (r1 > r2) {
//                     return false;
//                 }
//             }

//             if (!valid && w1.size() > w2.size()) {
//                 return false;
//             }
//         }

//         return true;
//     }
// };