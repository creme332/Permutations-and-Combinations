#include <iostream>
#include <vector>
#include <set>
#define ll long long
using namespace std;


set <int> UpdatedSet(set <int> Available, int key) {
    //Removes key from set and returns updated set
    Available.erase(key);
    return Available;
}

ll count(vector <int> sector, int i, set <int> Available, int maxsum) {

    if (i == 0) { //all sectors are filled. validate.
        if (sector[sector.size() - 2] + sector[sector.size() - 1] + sector[0] < maxsum) {
            if (sector[sector.size() - 1] + sector[0] + sector[1] < maxsum) {
                for (auto i : sector) { cout << i << " ";}
                cout << "\n";
                return 1;
            }
            else { return 0; }
        }
    }

    ll sum = 0;

    for (auto k : Available) {
        if (i == 1) {
            sector[i] = k;
            sum += count(sector, i + 1, UpdatedSet(Available, k), maxsum);
        }
        else {
            if (sector[i - 2] + sector[i - 1] + k < maxsum) { //sum of last two sectors and current sector must be < maxsum
                sector[i] = k;
                sum += count(sector, (i + 1) % sector.size(), UpdatedSet(Available, k), maxsum);
            }
            else {break;}
        }

    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int k = 10; // k sectors and [1,k] numbers

    set <int> Available;
    vector <int> sector;
    for (int i = 1;i <= k;i++) { Available.insert(i); sector.push_back(0); }
    sector[0] = 1; //fixed pivot
    Available.erase(1);

    //fill sectors [1, k-1] with numbers [2, k]
    ll ans = count(sector, 1, Available, 19);
    cout << ans<<"\n";



}
