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
            for(int i = 0; i < it->second.size();i ++){
                string pattern = it->second.at(i);
                if(word.size() >= pattern.size()) {
                    int hash = 0;
                    for (int j = 0; j < pattern.size(); j++) {
                        hash += word.at(j);
                    }
                    for (int j = 0; j < word.size() - pattern.size(); j++) {
                        if (hash == it->first) {
                            string tmpWord = "";
                            for (int k = 0; k < pattern.size(); k++) {
                                  tmpWord += word.at(j + k);
                            }
                            if (tmpWord == pattern) return true;
                            //word validation
                        }
                        hash -= word.at(j);
                        hash += word.at(j + pattern.size());
                    }
                }
            }
        }
        return false;
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
    vector<string> mickiewicz = {"tadeusz","wojsk","gerwaz","telimen","klucznik","podkomorz","wtenczas","litw","asesor","zos","horeszk","jac","soplic","moskali","protaz","dabrowski","strzelc","bernardyn","dobrzyns","biezy","chrzciciel","stolnik","maci","charty","jegry","krzyk","dobrzynsk","mopanku","rzecze","kropiciel","kwestarz","rapier","bernardyn","buchman","konewka","kropic","hrab","jankiel","karabele","mack","major","moskal","polowanie","powiecie","scyzoryk","strzelby","chartow","dobyl","hejze","jegrow","litw","mysliw","stol","prus","ramiony","rebajlo","rykow","szabli","szczwacze","zascianku","ascka","dobrzyn","drazki","dziedzic","konop","kus","low","mysliwc","obadwa","ochmistrzyni","pleban","plut","ptastw","skoluba","sokol","wloscian","wszerz","zareczyn","brzytew","chwaly","dziedzic","jack","kniaziewicz","kniej","kontusza","kryjomu","kurki","mazurk","mospanie","myslil","nazbyt","oblaw","ogary","polow","polszcze","pospieszal","pozew","rymsza","rzadka","sasiedzie","sokol","spuszcza","tabaki","wyczha","wytknal","zawzdy","blyszczac","dobyw","dumal","francuz","galk","ganek","karczm","kichnal","ksie","lachy","liscie","litewski","losie","mozem","natencz","ogon","ogorki","pacierz","parkan","poglada","polsk","przemian","psiarn","publico","pukle","rejta","roznie","swiadki","szabel","szlachc","szpada","traw","waszec","wczora","wiesniacz","wiln","wnuk","wodz","wojewod","zajazd","zazyl","zdala","ziela","zwawo","alkowy","bernardynie","biesiady","brat","bryka","brzucha","czynownik","dabrowskiego","dalbog","denassow"};
    vector<string> prus = {"wokulsk","izabel","rubli","rzecki","baron","ignac","stach","ochocki","wasowsk","starski","stawsk","szlangbaum","prezesow","szuman","naturalni","adwokat","hrabin","maruszewicz","fotel","geist","lecki","mraczewski","florentyna","klejn","krzeszowsk","odparla","kupiec","lisiecki","procent","kamienice","prezesowej","stanislaw","kobie","starusz","mincel","misiewiczowa","klacz","subiekt","lecka","paryz","spolki","stosunki","wirski","krzeszowsk","suzin","lecki","przedpokoj","radc","stawka","meliton","felicj","salon","wasowskiej","diabla","mezczyzn","wtracil","szumana","gabinetu","wariat","wyobraz","adwokata","leckiego","maruszewicza","ochockiego","racji","raczek","spolke","krzeszowski","rezultacie","spol","heluni","ignac","mikolaj","szescdziesiat","diabli","hopfer","kupc","lal","pociag","kupcem","miesiecy","mraczewski","pietnascie","akurat","handel","komorne","kupuje","lalke","patkiewicz","pietro","spacer","szprot","ewelina","franc","frankow","teatru","bilet","herbate","powoz","suzin","fizjognomia","hotelu","jumart","klaczy","kwadrans","rossiego","wdow","wysocki","arystokrac","bulgar","subiek","zarumienil","kuzyn","licytacj","ochocki","wagon","zobaczywszy","czterdziesci","dlug","fotel","interes","kapital","klejna","lokal","metal","okaz","osiem","rossi","rozmawial","spodni","dziesiatej","kanap","kupc","marianna","palmieri","rumieniac","sprzedal","dorozki","kamienic","lazien","malgorzat","molinari","myslal","osmej","stroz","subiektow","szostej","wegrowicz","zaklopotan","adres","awantur","dorozke","franc","komornik","krzeszowskiego","mezczyzn","mincla","tomasza","binokle","chlodno","domansk","dziewiatej","galanteryjny","groszy","jejmosc","klasy","kolumn","kontent","ladne","mizern","oberman","odezwal","pensje","piotrowicz","pretensji","procent"};
    vector<string> sien = {"winic","petron","lig","cezar","albow","chilo","ursus","piotr","chrzescijan","apostol","eunice","ancjum","nerona","pomponia","atrium","pomponii","niewolni","chilona","ostrianum","tygellinus","aulusow","bogo","poppea","aulus","apostol","niemal","chilon","glauka","tygellina","cyrku","naokol","uczynic","pretoria","tygellin","uczynil","tarsu","glaukus","arenie","aulusa","kroton","chryzotemis","marku","augustianie","poppei","triclinium","aren","augustian","kryspus","lektyki","achai","czynil","greka","odrzekl","kroto","linus","linusa","nazariusz","amfiteatr","miria","palatyn","sene","wiezie","westyn","cubicul","zatybrze","aren","odnalezc","poczucie","willi","dziewic","grecji","grec","neapolis","plaucjusz","centurion","igrzysk","kryspa","lektyke","miedzianobrod","miluje","przerazen","swiatyn","barank","chilonie","czynic","herkules","igrzysk","ogrodow","przeto","rzymski","trybun","uczynila","augusty","chrzescijanom","gladiatorow","jowisza","nieprzyjaciolmi","palatynu","sestercji","tunike","watyniusz","chilon","palatyn","podium","augustian","aulusowi","lukan","niechybnie","orszak","porta","pozarem","scewinus","senecjo","vicus","wyzwolenc","zakladnicz","zatybrzu","zgube","aulusowie","barbarzyncy","cnot","grecyn","odnajdz","patrycjusz","polluksa","poszukiwania","tuliusz","wigil","witeli","wyznawc","zlotowlos","aulusom","kaplani","nakazuj","pochodni","rozpoznac","senatoro","seneki","tygellinowi","uczyn","zadzy","zbawiciel","carissime","chilonem","cytr","czyniono","eurycjusz","lektyk","niger","opieka","ostii","peplum","petroniuszem","plaucjusz","pochodni","prefekt","szmaragd","tygellinem","uczyni","west","zatybrz","ahenobarba","czuwac","czynil","dobrem","dochodzily","grec","kaplan","kastor","kryspinil",};
    RollingHash * micRollingHash = new RollingHash(mickiewicz, 0);
    RollingHash * prusRollingHash = new RollingHash(prus, 1);
    RollingHash * sienRollingHash = new RollingHash(sien, 2);
    string line;
    getline(cin, line);
    vector<string> args = split(line, {' '});
    int n = stoi(args[0]);
    for(int i = 0; i < n; i ++){
        getline(cin, line);
        vector<string> words = split(line, {',','.', '\"', '\'', ';', ':','!','?', ' '});
        words = castToSmall(words);
        int micCount = 0;
        int sienCount = 0;
        int prusCount = 0;
        for(int i = 0; i < words.size(); i ++){
            micCount += micRollingHash->isInHashMap(words.at(i));
            sienCount += sienRollingHash->isInHashMap(words.at(i));
            prusCount += prusRollingHash->isInHashMap(words.at(i));
        }
        int bestCount = micCount;
        int bestAuthor = 0;
        if(prusCount > bestCount) {
            bestCount = prusCount;
            bestAuthor = 1;
        }
        if(sienCount > bestCount) {
            bestCount = sienCount;
            bestAuthor = 2;
        }
        //cout<<bestAuthor<<endl;
        if(bestAuthor == 0)cout<<"Mickiewicz";
        if(bestAuthor == 1)cout<<"Prus";
        if(bestAuthor == 2)cout<<"Sienkiewicz";
        cout<<endl;
    }
    return 0;
}