#include "postfix.h"
#include <gtest.h>
#include "postfix.cpp"

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix p);
}
TEST(TPostfix, can_get_infix)
{
	TPostfix p("a-b*c");
	EXPECT_EQ("a-b*c", p.GetInfix());
}
TEST(TPostfix, can_get_postfix)
{
	TPostfix p("a-b*c");
	p.ToPostfix();
	EXPECT_EQ("a,b,c,*,- ", p.GetPostfix());
}
TEST(TPostfix, can_check_true_infix)
{
	TPostfix p("a-b*c");
	ASSERT_NO_THROW(p.ToPostfix());
}
TEST(TPostfix, can_check_false_brackets)
{
	TPostfix p("(a-))b*c");
	ASSERT_ANY_THROW(p.ToPostfix());
}
TEST(TPostfix, can_check_false_operations)
{
	TPostfix p("a-+b*c");
	ASSERT_ANY_THROW(p.ToPostfix());
}
TEST(TPostfix, can_check_false_positioning)
{
	TPostfix p("a-+bc");
	ASSERT_ANY_THROW(p.ToPostfix());
}
TEST(TPostfix, can_calculate)
{
	TPostfix p("(10+10)*(15+15)");
	EXPECT_EQ(600, p.Calculate());
}
TEST(TPostfix, can_calculate_large_infix)
{
	TPostfix p("(10+10)*(15+15)/20+(40-10)-50*3/2+((75+15)/6)");
	EXPECT_EQ(0, p.Calculate());
}
TEST(TPostfix, cant_calculate_wrong_infix)
{
	TPostfix p("()10+10)*(15+15)/20+(40-10)-50*3/2+((75+15)/6)");
	ASSERT_ANY_THROW(p.Calculate());
}

