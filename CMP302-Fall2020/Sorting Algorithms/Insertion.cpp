/**
 * Insertion sort: works similar to the way you sort playing cards
 * We split the array virtually into sorted and unsorted parts and repeatably
 * Pick and element from the unsorted and place it in it's correctly place in the sorted par
 * */

/**
 * In-Place algorithm: true
 * Complexity: O(n^2)
 * Stable: true
 * */
void InsertionSort(vector<int> &a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int &i : a) {
        cin >> i;
    }

    InsertionSort(a);

    for (int i :  a) {
        cout << i << endl;
    }
}
