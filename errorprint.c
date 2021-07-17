void ErrorCheck(int ErrorValue, int *stack_a)
{
	if (ErrorValue > 0)
		return ();
	free(stack_a);
	printf("Error!");
}
//why did i make this though
//you're useless
