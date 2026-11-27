class Solution {
public:
    string robotWithString(string s) {
        // process to do 
        /*
        1 . preprocess = calculate MinToCharRight
        2 . s[i] --> t --->paper
        3. i++
        4. if(!t.empty()) -->push all to paper
        */
        int n = s.size();
        vector<char>MinToCharRight(n);
        MinToCharRight[n-1] = s[n-1]; // intiallize the last char of string to MinToCharRight because ther is nothig on right;
        for(int i =n-2; i>=0; i--){
            MinToCharRight[i] = min(s[i], MinToCharRight[i+1]);
        }
        string t = "";
        string paper = "";
        int i =0;
        while(i<n){
            t.push_back(s[i]);
            char minchar = (i+1) <n ? MinToCharRight[i+1] : s[i];
            while(!t.empty() && t.back() <= minchar){
                paper += t.back();
                t.pop_back();
            }
            i++;
        }
        while(!t.empty()){
            paper += t.back();
            t.pop_back();
        }
        return paper;
    }
};