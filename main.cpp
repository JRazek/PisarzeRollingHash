#include <iostream>
#include <map>
#include <vector>

using namespace std;
bool isInMap(const map<int, vector<string>> &hashMap, int key){
    return (hashMap.find(key) != hashMap.end());
}
struct RollingHash{
    map<int, vector<string>> hashMap;
    int author;
    RollingHash(vector<string> v, int author){
        for(int i = 0; i < hashMap.size(); i ++){
            string word = v.at(i);
            int hash = getWordHash(word);
            if(!isInMap(hashMap, hash)){
                hashMap.at(hash) = vector<string>();
            }
            hashMap.at(hash).push_back(word);
        }
        this->author = author;
    }
    int getWordHash(string word){
        int hash = 0;
        for(int j = 0; j < word.size(); j ++){
            hash += word[j];
        }
        return hash;
    }
    bool isInHashMap(string word){
        int hash = getWordHash(word);
        if(isInMap(this->hashMap, hash)){
            for(int i = 0; i < hashMap.at(hash).size(); i ++){
                string s = hashMap.at(hash).at(i);
                if(s == word) return true;
            }
        }
        return false;
    }
};

vector<string> split(string str, char divider){
    vector<string> result;

    string currWord = "";
    for(int i = 0; i < str.size(); i ++){
        currWord+=str[i];
        if(str[i] == divider || str.size()-1 == i){
            result.push_back(currWord);
            currWord = "";
        }
    }
    return result;
}

int main() {
    vector<string> mickiewicz = {"tadeusz","wojski","gerwazy","telimena","klucznik","podkomorz","wtenczas","litw","asesor","zosi","horeszkow","jac","soplic","maciej","soplic","moskal","protaz","dabrowski","strzelc","bernardyn","dobrzyns","biezy","chrzciciel","stolnik","charty","jegry","krzykneli","dobrzynski","mopanku","rzecze","kropiciel","kwestarz","rapier","bernardyna","buchman","konewka","kropic","hrabie","jankiel","karabele","klucznik","macka","majorze","moskal","moskala","polowanie","powiecie","scyzoryk","strzelby","chartow","dobrzynskich","dobyl","hejze","jegrow","litwa","mysliwi","stola","litewsk","prusak","ramion","rebajlo","rykow","szabli","szczwacze","zasciank","ascka","asesor","dobrzyn","drazki","dziedzic","konopie","kus","lowa","mysliwc","obadwa","ochmistrzyni","pleban","plut","podkomorz","ptastwo","skoluba","sokol","wloscian","wszerz","zareczyn","brzytew"};
    RollingHash * rh = new RollingHash(mickiewicz, 0);
    string line;
    getline(cin, line);
    vector<string> args = split(line, ' ');
    for(int i = 0; i < args.size(); i ++){
        cout<<args.at(i);
    }
    return 0;
}