template <typename T>
class Iterator
{
	public:
		Iterator(void);
		~Iterator(void);

		virtual bool is_done(void) = 0;
		virtual void advance(void) = 0;

	protected:
		size_t curr_;
};
