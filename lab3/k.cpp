#include <iostream>
#include <vector>

using namespace std;

int binary_search_solution(const vector<int>& chisla, int x) {
    int n = chisla.size();
    vector<long long> prefix(n + 1, 0);
    
    // Создаем префиксные суммы
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + chisla[i];
    }
    
    int min_length = n + 1;
    
    for (int i = 0; i < n; i++) {
        int left = 0, right = i;
        int best = -1;
        
        // Бинарный поиск по начальной позиции
        while (left <= right) {
            int mid = (left + right) / 2;
            if (prefix[i + 1] - prefix[mid] >= x) {
                best = mid;
                left = mid + 1; // ищем более короткий подмассив
            } else {
                right = mid - 1;
            }
        }
        
        if (best != -1) {
            min_length = min(min_length, i - best + 1);
        }
    }
    
    return min_length;
}
int main(){
    int n, m;
    cin >> n >> m;

    vector<int> chisla(n);

    for(int i=0; i<n; i++){
        cin >> chisla[i];
    }

    cout << binary_search_solution(chisla, m);
}