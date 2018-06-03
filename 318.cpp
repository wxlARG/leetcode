#include<iostream>
#include<sstream>
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stdlib.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;

int maxProduct(vector<string>& words)
{
    int result = 0;
    vector<int> len(words.size(),0);
    vector<vector<int>> cache(26);

    for(int i=0; i<words.size(); ++i)
    {
        len[i] = words[i].size();
        vector<bool> tmp(26,0);
        for(int j=0; j<words[i].size(); ++j)
            tmp[words[i][j]-'a']=1;

        string s;
        for(int j=0; j<26; ++j)
            if(tmp[j])
                s+=j+'a';

        words[i] = s;
    }

    for(int i=0; i<words.size(); ++i)
    {
        vector<int> st(26,0);
        for(int j=0; j<words[i].size(); ++j)
        {
            int pos = words[i][j] - 'a'; 
            cache[pos].push_back(i);
            st[pos]=1;
        }

        for(int j=0; j<26; ++j)
            if(!st[j])
                for(int k=0; k<cache[j].size(); ++k)
                {
                    int pos = cache[j][k];
                    bool flag = 1;
                    for(int t=0; t<words[pos].size(); ++t)
                        if(st[words[pos][t]-'a'])
                        {
                            flag = 0;
                            break;
                        }
                    if(flag)
                        result = len[pos]*len[i] > result ? len[pos]*len[i] : result;
                }
    }
    return result;
}

int main()
{
//    vector<string> words {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    vector<string> words {"kholggi","llgmjmiaeopgikdpbgfjiiiepfmkenjbfi","fbhgdpohjkgcfgheajkoffbeecf","bpkpbaklakbiliklehfmemdodlmkkgemofdookbcdfhhlbkea","adhdggdmgclbkbcen","nokikedkmlb","cpdcpcgkaopoeflalgedobjldgjjken","cbpdpkdfnifnbpajpbalmanpidaenhmdohklgfebcbmlpp","fhajokemeopemigbbeifamnj","ckeoibgeflkobfelfogkemfpbdmdo","cijfcemhhejogmjfhjfhmmpic","ofoa","hkehnkedadanejflfipjenaljijoalenohjof","nociipbdcicmddkjckfaajiipkcaoacfffgkdjnabag","cglclgggghpcapmddfgm","fkf","kbjhjpblfkceebpfndafnchlcleblconighipjljadmfaipee","fjhkpdilbeamdgedlifnbjioalaemlcgbhcibb","igkpnlakmeneihdadibhhpbieeiobcefdbang","jcf","igbnilffaanaedcomejmcgcplnfbkfbadlhkhpfkobpdmgbahg","mmgfjaededelcdjgpbfkffodbkcpchfakfplpnll","gfbjlgnpjkgdboijmljkljmmdpdhoohk","pdfadgfklggkeioilphkpaejgbmckgopncedc","oapmgijappkbmdoo","ibpbikkdmenpjphafpfcahjgnncaokchpjjc","dlk","jbohcnh","jniinmmhalabapbdgfoalkjcbahbiooicfkhknl","biah","nnkmiieadndk","mldikgibncfkgpifgochjpcmgbdmobdbgioaidj","hjapcfbi","cdfeceffm","mnaaefgn","kccopheleffiphddnekenlmjcfpnengndbe","djgaandmgkfkcijmlljnonloepmkkk","bekkkjccbkodanogabjnffmhhcpnoghojlpnmmoldeif","pdeikopjihddpclapdfemimacapljbojehfomiehfoaolmn","annhjophmhmbplmkepenpahnjcmebifnmmhocflefgmi","lcagjfee","henmnmefhpjdhfobpfnbakmpofllolophkkcfdibkgp","abmjhfnhojcikchgnfnohaenomjccdaamkkpdoahhjebpl","fgnliinegkbdcdcj","cclhnckm","nnakdelghnljcgldnhgkkbhbnj","cfdgbhmijmbdfgohmpgkfiolbkbafbocaoibfbnpnokpajhgppb","bpjijpohekphdnhnighhibnolmaioeeblnhopabk","hlldpjnjihkpnmelhhajdnhooaickpkciinpmhedapmkd","jmihapkhigipipcdpfemphicjbadpcjblegdfgcgapli","idmmkjgjphphdnciobmgaiadbfaihajblfhpbi","modmjcieopocn","bcgcomopmgbkaledacoelkbeifipfhpaknkmpejipccj","hjdmk","bdjcmibkcfegandjiachllfkbkcdfbcmkglbpnbempmgaiko","jcdjckipnhbdkcalccheodcblfhokoojamplcmiml","cdjgildkbdgjblpfijffflppik","bdhpkmkflofbnhjcpkgjekggpknjpn","bhgbobofhcbgkckabjjfldegfhjelmmlbmdgafnllejp","hgilpdnnikaadckalmcapek","nhbbfgplgjhidcgcobgddkognfd","fmhnenglb","nacnggnebm","cefnkoedioonkbbikaploobgnnjipallbfopldjipiglmn","epejjikaeooifbeimkgpcoddnifmljebiip","kgeenaejlbojggbjcbofdcknnkgljnikbhcjcoelpghdbmoco","ngebkdbbfpcepacdphclfhjnhkcppnigjkmmgjmacjh","ako","eldphibhhppalii","gfo","likdoipclkkknbgmaekhcphnhgnnloldjbpdc","bdohelllcapociomkgdij","hdigniknfdpdnjlgkc","bemfbfdnkmja","eclfkeahebpbck","dibodhbmbjlpeeemaigeoihnkgcniddiibekfpknlbpcakkncmf","bggknknefkp","jngbccimnnkmbfmabelkhdbbfdmob","hn","mlmdpgim","blnpnffngkaakhpodgdeenihhgpokphlkkfagkkogcbg","ekahebofdohlbhcehklpeapncokihjjekffkbp","emikmmoppeekdeaoedepclhgaajcaicigdejbbcgibigfj","ml","mkacjclepicidnfoief","anfeepjipheodidmhikpbci","odcclcpkoflhm","nkhnnncpoolbhjllcolbjfckibgemmgioakgfdpobgcjl","mmcmnkkamjpchmlhakhalbcmc","hppmgkiekoigbdoggeanbnadeehdildheigeabcfop","nglkekhlaiebplnekklljdfophahkpnpjkahb","dkecomflljmoalgbpfjb","nlifhdoaolojlmjgkfeojlcblnngiedgeamladhdhpdjeiach","bhaig","khgppheacdddjbiofkm","bpphigmmpmepjdcdoeobblomjackljmhgmodincknklfdeh","fi","doiknfdooennlmcklafedjmockfnio","alfnibnifbbdcpnmjfccmckjbmfnh","clcllhdbpicfhkbajmmhiackjdgnhgggndioookik","nogbhopioblacajnhoncpnoak","pmnmp","jobcpilbmngpp","hegdlefbc","mjljnbecoekcndic","dalckbpofigibmpmlkigi","dpejeoloooaeagbmnc","iheaemjgfgmclmpejnjbkohcdjjpfldhano","plnldodolhfnijjcafkfepddpcfjjmbpoghopab","bhpggffjaicnojbbnokgficonpkffknjbcjodncmdjfalekhm","pmkggmeldpipcmfndgicfhhohcahcobkh","aohfekcila","defeedbnkicloahcibblemfo","ai","hghdofgahfdjilblbpbdbhnmog","ibngemdmnmmkfkdaobokpemkbmfmg","ankadklbncpdaojcbhfhfahikpehaemhemnnlldfpoidglikpgh","edmkdoaomlnllgafbdkebcdk","flbciibbdidfpjhfpofhepbokmgfipdko","oaod","nicnohodagkknnpcbjlpgokkaeamgdekbdjoailoo","mjakpconbkemocoikib","kendpbgmpoebodkgbnbdmnnecdnmbiehhc","hemlokmlcogkpbjimeloohjecmklhafdcmokabn","moikmpgiehfkoddjddoelomhjacklhp","okfndbaonblghmnaakhpmjlcfeiflkeboonojniim","nfekfg","ppljegifmcmloeppajdpclognnpeikbcedbomnmmmgfl","bhkei","imeilenon","ncpienpneblahhahglnbjbmmcigghcaddbdjl","elmjjnomefbodgahncjk","encaplcnolklpgpgdckcjpeilnbhcamlackiiocnongee","kobjellmmgikooojnfjokdhhnkhpalbojbjjanflhdabiaj"};
    int result = maxProduct(words);
    cout << result << endl;
    return 0;
}
