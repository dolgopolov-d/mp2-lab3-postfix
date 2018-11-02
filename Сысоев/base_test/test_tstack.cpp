#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> st(5));
}
TEST(TStack, cant_create_stack_with_too_large_length)
{
	ASSERT_ANY_THROW(TStack<int> st(1000));
}
TEST(TStack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> st(-5));
}
TEST(TStack, can_get_max_size)
{
	TStack<int> st(5);
	EXPECT_EQ(5, st.max_size());
}
TEST(TStack, can_get_size)
{
	TStack<int> st(5);
	st.push(1);
	EXPECT_EQ(1, st.Size());
}
TEST(TStack, can_push)
{
	TStack<int> st(5);
	st.push(1);
	EXPECT_EQ(1, st.Top_el());
}
TEST(TStack, cant_push_if_full)
{
	TStack<int> st(1);
	st.push(1);
	ASSERT_ANY_THROW(st.push(1));
}
TEST(TStack, cant_pop_if_empty)
{
	TStack<int> st(1);
	ASSERT_ANY_THROW(st.pop());
}
TEST(TStack, cant_get_top_element_if_empty)
{
	TStack<int> st(1);
	ASSERT_ANY_THROW(st.Top_el());
}
TEST(TStack, cant_get_priority_if_empty)
{
	TStack<int> st(1);
	ASSERT_ANY_THROW(st.Prior());
}
