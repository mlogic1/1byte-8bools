#ifndef MULTIBOOL_H
#define MULTIBOOL_H

#include <stdexcept>

class MultiBool
{
	public:
		MultiBool()
		{
			Clear();
		}

		bool GetBoolAt(int index) const
		{
			if (index < 0 || index > 7){
				throw std::out_of_range("Index out of range");
			}
			
			const uint8_t mask = (1 << index);
			return (m_data & mask);
		}

		void SetBoolAt(int index, bool value)
		{
			if (index < 0 || index > 7){
				throw std::out_of_range("Index out of range");
			}
			if (value){
				m_data |= 1UL << index;
			}else{
				m_data &= ~(1UL << index);
			}
		}

		void Clear()
		{
			for (int i = 0; i < 7; ++i)
				m_data &= ~(1UL << i);
		}

	private:
		uint8_t m_data;
};

#endif // MULTIBOOL_H