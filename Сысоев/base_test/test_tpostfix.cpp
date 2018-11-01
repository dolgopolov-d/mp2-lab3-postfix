#include "postfix.h"
#include <gtest.h>

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
	EXPECT_EQ(true, p.IsValidInTotal());
}
TEST(TPostfix, can_check_false_brackets)
{
	TPostfix p("(a-))b*c");
	EXPECT_EQ(false, p.IsValidByBrackets());
}
TEST(TPostfix, can_check_false_operations)
{
	TPostfix p("a-+b*c");
	EXPECT_EQ(false, p.IsValidByOpers());
}
TEST(TPostfix, can_check_false_positioning)
{
	TPostfix p("a-+bc");
	EXPECT_EQ(false, p.IsValidByPos());
}
TEST(TPostfix, can_calculate)
{
	TPostfix p("(10+10)*(15+15)");
	EXPECT_EQ(600, p.Calculate());
}

