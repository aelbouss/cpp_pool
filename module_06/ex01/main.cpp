# include "Serializer.hpp"

int	main(void)
{

	Data d("anass");
	Data	*p = &d;
	Data	*r;

	
	uintptr_t rr = Serializer::serialize(p);
	r = Serializer::deserialize(rr);

	std::cout << "address : original : " << p << std::endl;
	std::cout << "address : deserialized : " <<  r << std::endl;
	std::cout << "value : original : " << p->get_str() << std::endl;
	std::cout << "value : deserialized : " <<  r->get_str() << std::endl;
	
	return 0;
}