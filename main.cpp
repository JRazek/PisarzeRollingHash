#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
bool isInMap(const map<int, vector<string>> &hashMap, int key){
    return (hashMap.find(key) != hashMap.end());
}
bool vectorContains(vector<char> v, char k){
    return (count(v.begin(), v.end(), k));
}
vector<string> castToSmall(vector<string> w){
    for(int i = 0; i < w.size(); i ++){
        for(int j = 0; j < w.at(i).size(); j ++){
            w.at(i).at(j) = tolower(w.at(i).at(j));
        }
    }
    return w;
}
struct RollingHash{
    map<int, vector<string>> hashMap;
    int author;
    RollingHash(vector<string> v, int author){
        for(int i = 0; i < v.size(); i ++){
            string word = v.at(i);
            int hash = getWordHash(word);
            if(!isInMap(hashMap, hash)){
                hashMap[hash] = vector<string>();
            }
            hashMap[hash].push_back(word);
        }
        this->author = author;
    }
    static int getWordHash(string word){
        int hash = 0;
        for(int j = 0; j < word.size(); j ++){
            hash += word[j];
        }
        return hash;
    }
    bool isInHashMap(string word){
        for (std::map<int, vector<string>>::iterator it = hashMap.begin(); it != hashMap.end(); it ++ ){
            if(it->second.size() <= word.size()){
                
            }
        }
    }
};

vector<string> split(string str, vector<char> divList){
    vector<string> result;

    string currWord = "";
    for(int i = 0; i < str.size(); i ++){
        if(vectorContains(divList, str[i])){
            result.push_back(currWord);
            currWord = "";
        }else{
            currWord+=str[i];
        }
        if(i+1 == str.size()){
            result.push_back(currWord);
        }
    }
    return result;
}

int main() {
    vector<string> mickiewicz = {"tadeusz","wojski","gerwaz","telimen","klucznik","podkomorz","wtencza","litw","asesor","zosi","horeszkow","jac","soplic","maciej","soplic","moskal","protaz","dabrowski","strzelc","bernardyn","dobrzyns","biezy","chrzciciel","stolnik","charty","jegry","krzykneli","dobrzynski","mopanku","rzecze","kropiciel","kwestarz","rapier","bernardyna","buchman","konewk","kropic","hrabi","jankiel","karabel","klucznik","macka","major","moskal","polowani","powie","scyzoryk","strzelb","chartow","dobrzynski","dobyl","hejze","jegrow","litw","mysliw","stola","litewsk","prusak","ramion","rebajlo","rykow","szabli","szczwacze","zasciank","ascka","asesor","dobrzyn","drazki","dziedzic","konopie","kus","lowa","mysliwc","obadwa","ochmistrzyni","pleban","plut","podkomorz","ptastwo","skoluba","sokol","wloscian","wszerz","zareczyn","brzytew"};
    RollingHash * micRollingHash = new RollingHash(mickiewicz, 0);
    string line;
    getline(cin, line);
    vector<string> args = split(line, {' '});
    int n = stoi(args[0]);
    for(int i = 0; i < n; i ++){
        getline(cin, line);
        vector<string> words = split(line, {',','.', '\"', '\'', ';', ':','!','?', ' '});
        words = castToSmall(words);
        int mic = 0;
        int sien = 0;
        int prus = 0;
        for(int i = 0; i < words.size(); i ++){
            mic += micRollingHash->isInHashMap(words.at(i));
           // cout<<words.at(i);
        }
        cout<<mic;
    }
    return 0;
}