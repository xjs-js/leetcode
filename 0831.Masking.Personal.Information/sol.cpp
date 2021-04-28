class Solution {
private:
    string markEmail(string& S, int pos) {
        string relt = "";
        string stars(5, '*');

        relt += tolower(S[0]);
        relt += stars;
        relt += tolower(S[pos-1]);

        relt += "@";
        for (int i = pos+1; i < S.size(); ++i) {
            relt += tolower(S[i]);
        }
        
        return relt;
    }
    
    string markTel(const string& S) {
        string nums;
        
        for (auto c : S) {
            if (isdigit(c)) {
                nums += c;
            }
        }
        
        string relt;
        if (nums.size() > 10) {
            int over = nums.size() - 10;
            string prefix(over, '*');
            relt += "+";
            relt += prefix;
            relt += "-";
        }
        
        relt += "***-***-";
        string last(nums, nums.size() - 4, 4);
        relt += last;
        return relt;
    }
public:
    
    
    
    string maskPII(string S) {
        // is an email
        size_t symbolPos = S.find("@");
        if (symbolPos != string::npos && S.size() >= 8) {
            return markEmail(S, symbolPos);
        } else if (S.size() >= 10) {
            return markTel(S);
        }
        
        return "";
    }
};
