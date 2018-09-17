typedef class Statement_struct *Statement;
typedef class Expression_struct *Expression;
# line 1 "ast.m"

# line 6 "ast.cpp"
extern void MatchError(char *, int);
struct Statement_struct {
   int tag;
};
struct assignment_struct : Statement_struct {
   Expression lhs;
   Expression rhs;
   assignment_struct(
      Expression lhs,
      Expression rhs
   );
};
typedef assignment_struct *assignment_subtype;
#define assignment_tag 1
extern "C" assignment_struct *assignment (
      Expression lhs,
      Expression rhs
);
struct print_struct : Statement_struct {
   Expression x;
   print_struct(
      Expression x
   );
};
typedef print_struct *print_subtype;
#define print_tag 2
extern "C" print_struct *print (
      Expression x
);
struct ifstmt_struct : Statement_struct {
   Expression cond;
   Statement thenpart;
   Statement elsepart;
   ifstmt_struct(
      Expression cond,
      Statement thenpart,
      Statement elsepart
   );
};
typedef ifstmt_struct *ifstmt_subtype;
#define ifstmt_tag 3
extern "C" ifstmt_struct *ifstmt (
      Expression cond,
      Statement thenpart,
      Statement elsepart
);
struct whilestmt_struct : Statement_struct {
   Expression cond;
   Statement body;
   whilestmt_struct(
      Expression cond,
      Statement body
   );
};
typedef whilestmt_struct *whilestmt_subtype;
#define whilestmt_tag 4
extern "C" whilestmt_struct *whilestmt (
      Expression cond,
      Statement body
);
struct seq_struct : Statement_struct {
   Statement s1;
   Statement s2;
   seq_struct(
      Statement s1,
      Statement s2
   );
};
typedef seq_struct *seq_subtype;
#define seq_tag 5
extern "C" seq_struct *seq (
      Statement s1,
      Statement s2
);
struct empty_struct : Statement_struct {
   empty_struct(
   );
};
typedef empty_struct *empty_subtype;
#define empty_tag 6
extern "C" empty_struct *empty (
);
assignment_struct::assignment_struct (
   Expression lhs_value,
   Expression rhs_value
)
{
   tag = assignment_tag;
   lhs = lhs_value;
   rhs = rhs_value;
}
assignment_struct *assignment (
   Expression lhs_value,
   Expression rhs_value
)
{
   return new assignment_struct (
   lhs_value,
   rhs_value
   );
}
print_struct::print_struct (
   Expression x_value
)
{
   tag = print_tag;
   x = x_value;
}
print_struct *print (
   Expression x_value
)
{
   return new print_struct (
   x_value
   );
}
ifstmt_struct::ifstmt_struct (
   Expression cond_value,
   Statement thenpart_value,
   Statement elsepart_value
)
{
   tag = ifstmt_tag;
   cond = cond_value;
   thenpart = thenpart_value;
   elsepart = elsepart_value;
}
ifstmt_struct *ifstmt (
   Expression cond_value,
   Statement thenpart_value,
   Statement elsepart_value
)
{
   return new ifstmt_struct (
   cond_value,
   thenpart_value,
   elsepart_value
   );
}
whilestmt_struct::whilestmt_struct (
   Expression cond_value,
   Statement body_value
)
{
   tag = whilestmt_tag;
   cond = cond_value;
   body = body_value;
}
whilestmt_struct *whilestmt (
   Expression cond_value,
   Statement body_value
)
{
   return new whilestmt_struct (
   cond_value,
   body_value
   );
}
seq_struct::seq_struct (
   Statement s1_value,
   Statement s2_value
)
{
   tag = seq_tag;
   s1 = s1_value;
   s2 = s2_value;
}
seq_struct *seq (
   Statement s1_value,
   Statement s2_value
)
{
   return new seq_struct (
   s1_value,
   s2_value
   );
}
empty_struct::empty_struct (
)
{
   tag = empty_tag;
}
empty_struct *empty (
)
{
   return new empty_struct (
   );
}
# line 10 "ast.m"



# line 199 "ast.cpp"
struct Expression_struct {
   int tag;
};
struct eq_struct : Expression_struct {
   Expression x;
   Expression y;
   eq_struct(
      Expression x,
      Expression y
   );
};
typedef eq_struct *eq_subtype;
#define eq_tag 1
extern "C" eq_struct *eq (
      Expression x,
      Expression y
);
struct ne_struct : Expression_struct {
   Expression x;
   Expression y;
   ne_struct(
      Expression x,
      Expression y
   );
};
typedef ne_struct *ne_subtype;
#define ne_tag 2
extern "C" ne_struct *ne (
      Expression x,
      Expression y
);
struct lt_struct : Expression_struct {
   Expression x;
   Expression y;
   lt_struct(
      Expression x,
      Expression y
   );
};
typedef lt_struct *lt_subtype;
#define lt_tag 3
extern "C" lt_struct *lt (
      Expression x,
      Expression y
);
struct le_struct : Expression_struct {
   Expression x;
   Expression y;
   le_struct(
      Expression x,
      Expression y
   );
};
typedef le_struct *le_subtype;
#define le_tag 4
extern "C" le_struct *le (
      Expression x,
      Expression y
);
struct gt_struct : Expression_struct {
   Expression x;
   Expression y;
   gt_struct(
      Expression x,
      Expression y
   );
};
typedef gt_struct *gt_subtype;
#define gt_tag 5
extern "C" gt_struct *gt (
      Expression x,
      Expression y
);
struct ge_struct : Expression_struct {
   Expression x;
   Expression y;
   ge_struct(
      Expression x,
      Expression y
   );
};
typedef ge_struct *ge_subtype;
#define ge_tag 6
extern "C" ge_struct *ge (
      Expression x,
      Expression y
);
struct plus_struct : Expression_struct {
   Expression x;
   Expression y;
   plus_struct(
      Expression x,
      Expression y
   );
};
typedef plus_struct *plus_subtype;
#define plus_tag 7
extern "C" plus_struct *plus (
      Expression x,
      Expression y
);
struct minus_struct : Expression_struct {
   Expression x;
   Expression y;
   minus_struct(
      Expression x,
      Expression y
   );
};
typedef minus_struct *minus_subtype;
#define minus_tag 8
extern "C" minus_struct *minus (
      Expression x,
      Expression y
);
struct mult_struct : Expression_struct {
   Expression x;
   Expression y;
   mult_struct(
      Expression x,
      Expression y
   );
};
typedef mult_struct *mult_subtype;
#define mult_tag 9
extern "C" mult_struct *mult (
      Expression x,
      Expression y
);
struct divide_struct : Expression_struct {
   Expression x;
   Expression y;
   divide_struct(
      Expression x,
      Expression y
   );
};
typedef divide_struct *divide_subtype;
#define divide_tag 10
extern "C" divide_struct *divide (
      Expression x,
      Expression y
);
struct neg_struct : Expression_struct {
   Expression x;
   neg_struct(
      Expression x
   );
};
typedef neg_struct *neg_subtype;
#define neg_tag 11
extern "C" neg_struct *neg (
      Expression x
);
struct number_struct : Expression_struct {
   int x;
   number_struct(
      int x
   );
};
typedef number_struct *number_subtype;
#define number_tag 12
extern "C" number_struct *number (
      int x
);
struct name_struct : Expression_struct {
   int location;
   name_struct(
      int location
   );
};
typedef name_struct *name_subtype;
#define name_tag 13
extern "C" name_struct *name (
      int location
);
eq_struct::eq_struct (
   Expression x_value,
   Expression y_value
)
{
   tag = eq_tag;
   x = x_value;
   y = y_value;
}
eq_struct *eq (
   Expression x_value,
   Expression y_value
)
{
   return new eq_struct (
   x_value,
   y_value
   );
}
ne_struct::ne_struct (
   Expression x_value,
   Expression y_value
)
{
   tag = ne_tag;
   x = x_value;
   y = y_value;
}
ne_struct *ne (
   Expression x_value,
   Expression y_value
)
{
   return new ne_struct (
   x_value,
   y_value
   );
}
lt_struct::lt_struct (
   Expression x_value,
   Expression y_value
)
{
   tag = lt_tag;
   x = x_value;
   y = y_value;
}
lt_struct *lt (
   Expression x_value,
   Expression y_value
)
{
   return new lt_struct (
   x_value,
   y_value
   );
}
le_struct::le_struct (
   Expression x_value,
   Expression y_value
)
{
   tag = le_tag;
   x = x_value;
   y = y_value;
}
le_struct *le (
   Expression x_value,
   Expression y_value
)
{
   return new le_struct (
   x_value,
   y_value
   );
}
gt_struct::gt_struct (
   Expression x_value,
   Expression y_value
)
{
   tag = gt_tag;
   x = x_value;
   y = y_value;
}
gt_struct *gt (
   Expression x_value,
   Expression y_value
)
{
   return new gt_struct (
   x_value,
   y_value
   );
}
ge_struct::ge_struct (
   Expression x_value,
   Expression y_value
)
{
   tag = ge_tag;
   x = x_value;
   y = y_value;
}
ge_struct *ge (
   Expression x_value,
   Expression y_value
)
{
   return new ge_struct (
   x_value,
   y_value
   );
}
plus_struct::plus_struct (
   Expression x_value,
   Expression y_value
)
{
   tag = plus_tag;
   x = x_value;
   y = y_value;
}
plus_struct *plus (
   Expression x_value,
   Expression y_value
)
{
   return new plus_struct (
   x_value,
   y_value
   );
}
minus_struct::minus_struct (
   Expression x_value,
   Expression y_value
)
{
   tag = minus_tag;
   x = x_value;
   y = y_value;
}
minus_struct *minus (
   Expression x_value,
   Expression y_value
)
{
   return new minus_struct (
   x_value,
   y_value
   );
}
mult_struct::mult_struct (
   Expression x_value,
   Expression y_value
)
{
   tag = mult_tag;
   x = x_value;
   y = y_value;
}
mult_struct *mult (
   Expression x_value,
   Expression y_value
)
{
   return new mult_struct (
   x_value,
   y_value
   );
}
divide_struct::divide_struct (
   Expression x_value,
   Expression y_value
)
{
   tag = divide_tag;
   x = x_value;
   y = y_value;
}
divide_struct *divide (
   Expression x_value,
   Expression y_value
)
{
   return new divide_struct (
   x_value,
   y_value
   );
}
neg_struct::neg_struct (
   Expression x_value
)
{
   tag = neg_tag;
   x = x_value;
}
neg_struct *neg (
   Expression x_value
)
{
   return new neg_struct (
   x_value
   );
}
number_struct::number_struct (
   int x_value
)
{
   tag = number_tag;
   x = x_value;
}
number_struct *number (
   int x_value
)
{
   return new number_struct (
   x_value
   );
}
name_struct::name_struct (
   int location_value
)
{
   tag = name_tag;
   location = location_value;
}
name_struct *name (
   int location_value
)
{
   return new name_struct (
   location_value
   );
}
# line 28 "ast.m"

