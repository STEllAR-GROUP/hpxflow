// #include <thread>
// #include <atomic>
// #include <cinttypes>
// using namespace std;

// #define BUFFER_SIZE 4096

// namespace hpx{
//     namespace flow {
//         class flowbuffer {
//             public :
                
//                 flowbuffer() {
//                     write.store(0);
//                     read.store(0);
//                 }
                
//                 template <typename T>
//                 bool try_push(T val) {
//                     const auto current_tail = write.load();
//                     const auto next_tail = increment(current_tail);
//                     if (next_tail != read.load())
//                     {
//                         buffer[current_tail] = val;
//                         write.store(next_tail);
//                         return true;
//                     }

//                     return false;  
//                 }
                
//                 template <typename T>
//                 void push(T val) {
//                     while( ! try_push(val) );
//                 }
                
//                 template <typename T>
//                 bool try_pop(T* pval) {
//                     auto currentHead = read.load();
                    
//                     if (currentHead == write.load()) {
//                         return false;
//                     }

//                     *pval = buffer[currentHead];
//                     read.store(increment(currentHead));

//                     return true;
//                 }
                
//                 template <typename T>
//                 T pop() {
//                     T ret;
//                     while( ! try_pop(&ret) );
//                     return ret;
//                 }
                
//             private :
//                 template <typename T>
//                 std::atomic<T> write ;
//                 template <typename T>
//                 std::atomic<T> read;
//                 V size = RING_BUFFER_SIZE;
//                 V buffer[RING_BUFFER_SIZE];
                
//                 template <typename X, typename U>

//                 U increment(X n) {
//                     return (n + 1) % size;
//                 }
//         };

//     }
// }
