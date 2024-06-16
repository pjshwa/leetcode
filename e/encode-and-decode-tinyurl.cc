class Solution {
public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    auto token = next_token();
    store_[token] = longUrl; 
    return UrlPrefix + token;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {        
    return store_[shortUrl.substr(UrlPrefix.size())];
  }
    
private:
  string next_token() {
    static string dict{"abcdefghABCDEFGH0123456789-"};
    static std::random_device rd;
    static std::mt19937 g(rd());
    
    string token{};        
    
    do {
      shuffle(begin(dict), end(dict), g);
      token.resize(0);
      sample(begin(dict), end(dict), back_inserter(token), 8, g);
    } while(store_.count(token));
    
    return token;
  }
private:    
  static const string UrlPrefix;
  unordered_map<string, string> store_;
};

const string Solution::UrlPrefix = "http://tinyleet.com/";
