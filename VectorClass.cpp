// Practice writing a Vector class for fun
// reference: https://www.youtube.com/watch?v=ryRf4Jh_YC0&ab_channel=TheCherno
template<typename T>
class Vector 
{
    public:
        Vector() {
            // alocate enough for 2 elements
        }
    private:
        T* m_Data = nullptr;

        size_t m_Size = 0;
        size_t m_Capacity = 0;
};