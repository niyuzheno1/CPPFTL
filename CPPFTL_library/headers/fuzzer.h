#pragma once
#include <vector>
#include <functional>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <map>
#define TYPE_NUMERIC 0
namespace CPPFTL
{
    template<typename T>
    class Fuzzer
    {
    public: 
        Fuzzer(){
            this->mElementGenerator = nullptr;
            this->mIsDifferent = false;
            this->mSeed = 0;
            this->mSize = 0;
            this->mMin = T();
            this->mMax = T();
            this->mFuzzingData = std::vector<T>();
        }
        ~Fuzzer(){

        }
        void setSeed(int seed){
            this->mSeed = seed;
        }
        void setType(int type){
            this->mType = type;
        }
        void setRange(T min, T max){
            this->mMin = min;
            this->mMax = max;
        }
        void setSize(int size){
            this->mSize = size;
        }
        void setIsDifferent(bool isDifferent){
            this->mIsDifferent = isDifferent;
        }
        void setElementGenerator(std::function<T(int)> generator){
            this->mElementGenerator = generator;
        }
        void generate(){
            this->mFuzzingData.clear();
            std::mt19937 mt(this->mSeed); 
            std::set<int> hasChosen;
            int retried = 0;
            for(int i = 0; i < this->mSize; i++){
                T element;   
                T tmp;
                switch (this->mType)
                {
                case  TYPE_NUMERIC:
                    while(retried <= 1000 * (this->mIsDifferent) + 1 - (this->mIsDifferent)){
                        tmp = this->generateNumeric(mt);
                        if(hasChosen.find(tmp) == hasChosen.end()){
                            break;
                        }
                    }
                    element = tmp;
                    break;
                default:
                    element = this->mElementGenerator(this->mSeed);
                    break;
                }
                this->mFuzzingData.push_back(element);
            }
        }
       
        //begin
        auto begin(){
            return this->mFuzzingData.begin();
        }
        //end
        auto end(){
            return this->mFuzzingData.end();
        }

        std::vector<T> allExclude(int index){
            std::vector<T> result;
            for(int i = 0; i < this->mFuzzingData.size(); i++){
                if(i != index){
                    result.push_back(this->mFuzzingData[i]);
                }
            }
            return result;
        }
        std::vector<T> allExclude(std::vector<T> exceptions){
            std::vector<T> result;
            for(int i = 0; i < this->mFuzzingData.size(); i++){
                bool isException = false;
                for(int j = 0; j < exceptions.size(); j++){
                    if(this->mFuzzingData[i] == exceptions[j]){
                        isException = true;
                        break;
                    }
                }
                if(!isException){
                    result.push_back(this->mFuzzingData[i]);
                }
            }
            return result;
        }
        void reportError(){
            std::cout << "Current Seed: " << this->mSeed << std::endl;
            std::abort();
        }

        template<typename U>
        void remember(std::map<T, U> &memory, T key, U value){
            memory[key] = value;
        }

    private:
        T generateNumeric(std::mt19937 & t){
            std::uniform_int_distribution<T> dist(this->mMin, this->mMax);
            return dist(t);
        }
        int mType;
        std::function<T(int X)> mElementGenerator; //make sure it won't be idempotent
        bool mIsDifferent;
        int mSeed;
        int mSize;
        T mMin;
        T mMax;
        std::vector<T> mFuzzingData;

        
    };
}
