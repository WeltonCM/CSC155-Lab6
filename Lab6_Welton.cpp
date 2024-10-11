/*
Name: Lab6_Welton
Author: Christopher Welton
Description: This program reads N^2 values from the keyboard and tests wether it is a magical square.
*/

#include<iostream>
#include<set>
#include<vector>

using namespace std;

bool areNumbersUnique(vector<int> nums){
    set<int> unique;
    for(int i =0; i< nums.size(); i++){
        unique.insert(nums[i]);
    }
    return unique.size() == nums.size();
}

bool isMagicSquare(vector<int> nums, int nValue){
    int magicSum = 0;

    for(int i=0; i<nums.size(); i += nValue){
        int nextRowSum = 0;
        for(int j = i; j < nValue + i; j++){
            nextRowSum += nums[j];
        }
        if(i != 0){
            if(magicSum != nextRowSum){
                return false;
            } 
        } else {
            magicSum = nextRowSum;
        }
    }

    for(int i = 0; i < nValue; i ++){
        int nextColSum = 0;
        for(int j = i; j < nums.size(); j += nValue){
            nextColSum += nums[j];
        }

        if(magicSum != nextColSum){
            return false;
        }
    }
    int topBottomDiagSum = 0;
    for(int i = 0; i < nums.size(); i+= nValue){
       topBottomDiagSum += nums[i];
    }
    if(magicSum != topBottomDiagSum){
        return false;
    }

    int bottomTopDiagSum = 0;
    for(int i = 0; i < nValue; i++){
        bottomTopDiagSum += nums[i * nValue + (nValue -1 -i)];
    }

    if(magicSum != bottomTopDiagSum){
        return false;
    }

    return true;
}

int main() {
    int nValue;
    cout << "Please enter a N value to determine the size of the matrix: ";
    cin >> nValue;
    vector<int> numbers(nValue * nValue);

    cout << "You will now enter " << nValue * nValue << " numbers." << endl;
    cout << "Please ensure your numbers are unique!" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    for(int i=0; i < numbers.size(); i++){
        string numberOrdinal;
        int value;
        bool validInput = false;

        switch(i + 1) {
            case 1:
                numberOrdinal = "st";
                break;
            case 2:
                numberOrdinal = "nd";
                break;
            case 3: 
                numberOrdinal = "rd";
                break;
            default: 
                numberOrdinal = "th";
                break;
        }
        do {
            cout << "Enter the " << i + 1 << numberOrdinal <<" number: " << endl;
            string input;
            getline(cin, input);

            try {
                value = stoi(input);
                numbers[i] = value;
                validInput = true;
            } catch (invalid_argument&){
                cout << "Error: Invalid input. Please enter a valid integer" << endl;
            }
        } while (!validInput);
    }

    if(!areNumbersUnique(numbers)){
        cout << "The numbers you input are not unique, program terminating...." << endl;
        return 0;
    }

    bool magic = isMagicSquare(numbers, nValue);
    if(magic){
        cout << "This is a magic square!" << endl;
    } else {
        cout << "This is not a magic square." << endl;
    }
    

    return 0;
}