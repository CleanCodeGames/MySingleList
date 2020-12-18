template<class T>
class Data {
    private:
    T m_value;

public:
	const T& get();
    void set(const T& value);
	Data(const T& value = 0);
	~Data();
};