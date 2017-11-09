int getNumberInRange(int minimum, int maximum)
{
	int range = maximum - minimum;
	return rand() % range + minimum;
}
