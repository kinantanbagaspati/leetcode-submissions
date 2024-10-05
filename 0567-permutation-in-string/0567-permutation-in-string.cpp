class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        int f1[32], f2[32];
        for(int i=0; i<32; i++){
            f1[i] = 0; f2[i] = 0;
        }
        for(int i=0; i<s1.length(); i++){
            cout << s1[i]-'a' << " vs "<< s2[i]-'a' << endl;
            f1[s1[i]-'a']++; f2[s2[i]-'a']++;
        }
        
        bool sama = true;
        for(int i=0; i<32; i++) sama = (f1[i] == f2[i]) && sama;
        if(sama) return true;
        cout << s1.length() << " <= " << s2.length() << endl;
        for(int i=s1.length(); i<s2.length(); i++){
            f2[s2[i-s1.length()]-'a']--;
            f2[s2[i]-'a']++;
            sama = true;
            //cout << i << ":";
            for(int j=0; j<32; j++){
                sama = (f1[j] == f2[j]) && sama;
                //cout << " " << f2[j];
            }
            //cout << endl;
            if(sama) return true;
        }
        return false;
    }
};