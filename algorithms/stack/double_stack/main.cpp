#include <exception>

class double_stack{
private:
	int* arr;
	int right;
	int left;
	size_t size;
public:

	double_stack(){
		size = 100;
		left = 0;
		right = size - 1;
		arr = new int[size];
	}

	bool push_left(const int value){
		if (left > right){
			int *temp = new int[2 * size];
			
			for (size_t i = 0; i < left; i++){
				temp[i] = arr[i];
			}

			for (size_t i = right + 1; i < size; i++){
				temp[i] = arr[i + size];
			}

		}
		arr[left] = value;
		left++;
		return true;
	}

	bool push_right(const int value){
		if (right < left){
			return false;
		}
		arr[right] = value;
		right--;
		return true;
	}

	int pop_left(){
		if (left == 0){
			throw std::runtime_error("Oops!");
		}

		left--;
		return arr[left];
	}

	int pop_right(){
		if (right == size - 1){
			throw std::runtime_error("Oops!");
		}
		right++;
		return arr[right];
	}
	
	int peek_left(){

	}

	int peek_right(){

	}

	~double_stack(){
		delete[] arr;
	}

	void temp_print(){
		for (size_t i = 0; i < size; i++){
			
		}
	}
};


int main(void){
	double_stack data;

	for (size_t i = 0; i < 7; i++){
		data.push_left(i);
	}

	// for (size_t i = 0; i > 7; i--){
	// 	data.push_right(i);
	// }
	//
	// data.temp_print();
	
	

}
