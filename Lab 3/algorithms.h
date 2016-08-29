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

    void List_Increasing(vector<int> &list){
        for(int i = 0;i < list.size();i++){
            list[i] = i;
        }
    }

    void List_Decreasing(vector<int> &list){
        for(int i = 0;i < list.size();i++){
            list[i] = (list.size()-1)-i;
        }
    }

    int* Random_List(int *list, int n){
        for(int i = 0;i < n-1;i++){
            list[i] = rand()%100 + 1;
        }
    }

    void Random_List(vector<int> &list){
        for(int i = 0;i < list.size();i++){
            list[i] = rand()%100 + 1;
        }
    }

    void Print_List(vector<int> list){
        cout << "[" << list[0];
        for(int i = 1;i < list.size();i++){
            cout << ", " << list[i];
        }
        cout << "]" << endl;
    }

    void Print_List(int *list, int n){
        cout << "[" << list[0];
        for(int i = 1;i < n;i++){
            cout << ", " << list[i];
        }
        cout << "]" << endl;
    }

    void QuickSort(vector<int> &list, int left, int right) {
		if(right > left){
		
			int v = list[right];
			int i = left;
			int j = right;
			int t;
			
			while(i < j){
			
				while(list[i] < v){
					i++;
				}
				
				while(j > i && list[j] >= v){
					j--;
				}
				
				if(j > i){
					t = list[i];
					list[i] = list[j];
					list[j] = t;
				}
			}
			
			t = list[i];
			list[i] = list[right];
			list[right] = t;
		
			QuickSort(list, left, i-1);
			QuickSort(list, i+1, right);
		}
    }

    void Random_List_Increasing(vector<int> &list, int key){
	    Random_List_Distinct(list, key);
        QuickSort(list, 0, list.size()-1);
	}

    int* selectionSort(int *list, int n){
        for(int i = 0;i <= n-2;i++){
            int minpos = i;
            for(int j = i+1;j <= n-1;j++){
                if(list[j] < list[minpos])
                    minpos = j;
            }
            int temp = list[minpos];
            list[minpos] = list[i];
            list[i] = temp;
        }
        return list;
    }   

    int* bubbleSort(int *list, int n){
        for(int i = n-1;i >= 1;i--){
            for(int j = 0;j <= i-1;j++){
                if(list[j] > list[j+1]){
                    int temp = list[j];
                    list[j] = list[j+1];
                    list[j+1] = temp;; 
                }
                    
            }
        }
        return list;
    }

    int* improved_bubbleSort(int *list, int n){
        for(int i = n-1;i >= 1;i--){
            int flag = 0;
            for(int j = 0;j <= i-1;j++){
                if(list[j] > list[j+1]){
                    flag = 1;
                    int temp = list[j];
                    list[j] = list[j+1];
                    list[j+1] = temp;; 
                }
                    
            }
            if(flag == 0)
                return list;
        }
        return list;
    }





    vector<int> selectionSort(vector<int> list, int n){
        for(int i = 0;i <= n-2;i++){
            int minpos = i;
            for(int j = i+1;j <= n-1;j++){
                if(list[j] < list[minpos])
                    minpos = j;
            }
            int temp = list[minpos];
            list[minpos] = list[i];
            list[i] = temp;
        }
        return list;
    }   

    vector<int> bubbleSort(vector<int> list, int n){
        for(int i = n-1;i >= 1;i--){
            for(int j = 0;j <= i-1;j++){
                if(list[j] > list[j+1]){
                    int temp = list[j];
                    list[j] = list[j+1];
                    list[j+1] = temp;; 
                }
                    
            }
        }
        return list;
    }

    vector<int> improved_bubbleSort(vector<int> list, int n){
        for(int i = n-1;i >= 1;i--){
            int flag = 0;
            for(int j = 0;j <= i-1;j++){
                if(list[j] > list[j+1]){
                    flag = 1;
                    int temp = list[j];
                    list[j] = list[j+1];
                    list[j+1] = temp;; 
                }
                    
            }
            if(flag == 0)
                return list;
        }
        return list;
    }

	void MergeSort(vector<int> &list, int left, int right){
		if(right-left > 0){
			vector<int> temp(list.size());
			int mid = (left + right)/2;
			MergeSort(list, left, mid);
			MergeSort(list, mid + 1, right);

			for(int i = mid;i >= left;i--){
				temp[i] = list[i];
			}

			for(int j = mid+1;j <= right;j++){
				temp[right + mid+1 - j] = list[j];
			}

			int i = left;
			int j = right;

			for(int k = left;k <= right;k++){
				if(temp[i] < temp[j]){
					list[k] = temp[i];
					i++;
				}

				else{
					list[k] = temp[j];
					j--;
				}
			}
		}
	}
	
	
	
	/*****************************
	*							 *
	*		  NEED TO DO		 *
	*						     *
	*****************************/
	void ImprovedMergeSort(vector<int> &list, int left, int right){
		if(right-left > 0){
			vector<int> temp(list.size());
			int mid = (left + right)/2;
			ImprovedMergeSort(list, left, mid);
			ImprovedMergeSort(list, mid + 1, right);

			for(int i = mid;i >= left;i--){
				temp[i] = list[i];
			}

			for(int j = mid+1;j <= right;j++){
				temp[right + mid+1 - j] = list[j];
			}

			int i = left;
			int j = right;

			for(int k = left;k <= right;k++){
				if(temp[i] < temp[j]){
					list[k] = temp[i];
					i++;
				}

				else{
					list[k] = temp[j];
					j--;
				}
			}
		}
	}



















