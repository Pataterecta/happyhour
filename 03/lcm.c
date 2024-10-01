// Assignment name  : lcm
// Expected files   : lcm.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function who takes two unsigned int as parameters and returns the
// computed LCM of those parameters.

// LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
// integer divisible by the both integers.

// A LCM can be calculated in two ways:

// - You can calculate every multiples of each integers until you have a common
// multiple other than 0

// - You can use the HCF (Highest Common Factor) of these two integers and
// calculate as follows:

// 	LCM(x, y) = | x * y | / HCF(x, y)

//   | x * y | means "Absolute value of the product of x by y"

// If at least one integer is null, LCM is equal to 0.

// Your function must be prototyped as follows:

//   unsigned int    lcm(unsigned int a, unsigned int b);

// 두 개의 양의 정수에 대해 최소 공배수를 구하는 함수를 작성하라는 내용 
// 주어진 두 수가 0이 아닌 경우 lcm
// 둘 중 하나라도 0이면 lcm 은 0
// lcm(4, 6) = 12

unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int n;	

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		n = a; // 시간 줄이기 용도 더 큰 값이 최소 공배수의 후보가 되기 때문
	else
		n = b;
	while (1) // 무한루프 시작 최소 공배수를 찾으면 종료됨
	{
		if (n % a == 0 && n % b == 0) // 두 수 모두로 나눌 수 있으면 최소 공배수임
			return (n);
		++n; // 두 수 모두로 나눠지지 않으면 n을 1씩 증가시키면서 다음 공배수를 찾아가기
	}
}
