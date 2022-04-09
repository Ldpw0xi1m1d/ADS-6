// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template <typename T, int sized>
class TPQueue {
 private:
        T *arr;
        int size;
        int first;
        int last;

 public:
      TPQueue() : first(0), last(0) {
            size = sized;
            arr = new T[size];
      }

       void push(T value) {
                int i = last-1;
                bool flag = 0;
                   while ((i >= first) && (value.prior > arr[i].prior)) {
                                flag = 1;
                                arr[i + 1] = arr[i];
                                arr[i] = value;
                                i--;
                        }
                        if (flag == 0) {
                             arr[last++] = value;
                             last++;
                        }
         }

        T pop() {
                    return arr[(first++) % size];
                }

        T front() {
                    return arr[first % size];
         }

        T back() {
                     return arr[(last - 1) % size];
        }
};

struct SYM {
       char ch;
       int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
