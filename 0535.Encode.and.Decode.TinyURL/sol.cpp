class Solution {
private:
    std::unordered_map<int, string> dict;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int hashValue = std::hash<string>{}(longUrl);
        dict.insert(std::make_pair(hashValue, longUrl));
        string encoded_suffix = to_string(hashValue);
        string encoded_prefix = "http://tinyurl.com/";
        return encoded_prefix + encoded_suffix;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string encoded_prefix = "http://tinyurl.com/";
        string encoded_suffix = shortUrl.erase(0, encoded_prefix.length());
        int hashValue = atoi(encoded_suffix.c_str());
        if (dict.find(hashValue) != dict.end()) {
            return dict[hashValue];
        }
        return "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));