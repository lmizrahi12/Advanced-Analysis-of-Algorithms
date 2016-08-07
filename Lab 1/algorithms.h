#include <vector>
using namespace std;
    void Print_List(vector<int> list);

    int Linear_Search(vector<int> list, int key){
		int index = -1;
		for(int i = 0;i < list.size();i++){
			if(list[i] == key){
				index = i;
				return index;
			}
		}
		return index;
	}
	
	int Binary_Search(vector<int> list, int key){
		int low = 0;
		int high = list.size() - 1;
		int mid = -1;
		int found = 0;
		
		while(low <= high && found == 0){
			mid = (low + high)/2;
			if(key == list[mid]){
				found = 1;
                return mid;
			}
			else{
				if(key < list[mid]){
					high = mid - 1;
				}
				else{
					low = mid + 1;
				}
			}
		}
		if(found == 0)
			mid = -1;
		return mid;
	}
	
	void Random_List_Distinct(vector<int> &list, int key){
		for(int i = 0;i < list.size();i++){
			int random = (int)rand()%(list.size()+100) + 1;
			while(random == key || Linear_Search(list, key) != -1) {
				random = (int)rand()%(list.size()+100) + 1;
			}
        if(list[i] == 0)
			list[i] = random;
		}
	}

    void Print_List(vector<int> list){
        cout << "[" << list[0];
        for(int i = 1;i < list.size();i++){
            cout << ", " << list[i];
        }
        cout << "]" << endl;
    }

    void QuickSort(vector<int> &arr, int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      if (left < j)
            QuickSort(arr, left, j);
      if (i < right)
            QuickSort(arr, i, right);
    }

    void Random_List_Increasing(vector<int> &list, int key){
	    Random_List_Distinct(list, key);
        QuickSort(list, 0, list.size()-1);
	}
