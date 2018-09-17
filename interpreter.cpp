# line 1 "interpreter.m"

# line 4 "interpreter.cpp"
#include "ast.f"
extern void MatchError(char *, int);
#include "ast.h"
# line 1 "interpreter.m"


extern "C" void printf(...);
extern "C" void execute(Statement s);

float   var[26];

int evaluate(Expression e)
{
    
# line 19 "interpreter.cpp"

// GENERATED FROM SOURCE LINE 10
{
Expression tmp0;
tmp0 = e;
{
Expression tmp3;
Expression x;
Expression tmp1;
Expression y;
Expression tmp2;
if (tmp0->tag != eq_tag) goto EndOfRule4;
tmp1 = ((eq_subtype) tmp0)->x;
tmp2 = ((eq_subtype) tmp0)->y;
x = tmp1;
y = tmp2;
# line 11 "interpreter.m"
  return evaluate(x) == evaluate(y);
        
# line 39 "interpreter.cpp"
goto EndOfMatch50;
EndOfRule4 : ;
}
{
Expression tmp7;
Expression x;
Expression tmp5;
Expression y;
Expression tmp6;
if (tmp0->tag != ne_tag) goto EndOfRule8;
tmp5 = ((ne_subtype) tmp0)->x;
tmp6 = ((ne_subtype) tmp0)->y;
x = tmp5;
y = tmp6;
# line 12 "interpreter.m"
  return evaluate(x) != evaluate(y);
        
# line 57 "interpreter.cpp"
goto EndOfMatch50;
EndOfRule8 : ;
}
{
Expression tmp11;
Expression x;
Expression tmp9;
Expression y;
Expression tmp10;
if (tmp0->tag != lt_tag) goto EndOfRule12;
tmp9 = ((lt_subtype) tmp0)->x;
tmp10 = ((lt_subtype) tmp0)->y;
x = tmp9;
y = tmp10;
# line 13 "interpreter.m"
  return evaluate(x) <  evaluate(y);
        
# line 75 "interpreter.cpp"
goto EndOfMatch50;
EndOfRule12 : ;
}
{
Expression tmp15;
Expression x;
Expression tmp13;
Expression y;
Expression tmp14;
if (tmp0->tag != le_tag) goto EndOfRule16;
tmp13 = ((le_subtype) tmp0)->x;
tmp14 = ((le_subtype) tmp0)->y;
x = tmp13;
y = tmp14;
# line 14 "interpreter.m"
  return evaluate(x) <= evaluate(y);
        
# line 93 "interpreter.cpp"
goto EndOfMatch50;
EndOfRule16 : ;
}
{
Expression tmp19;
Expression x;
Expression tmp17;
Expression y;
Expression tmp18;
if (tmp0->tag != gt_tag) goto EndOfRule20;
tmp17 = ((gt_subtype) tmp0)->x;
tmp18 = ((gt_subtype) tmp0)->y;
x = tmp17;
y = tmp18;
# line 15 "interpreter.m"
  return evaluate(x) >  evaluate(y);
        
# line 111 "interpreter.cpp"
goto EndOfMatch50;
EndOfRule20 : ;
}
{
Expression tmp23;
Expression x;
Expression tmp21;
Expression y;
Expression tmp22;
if (tmp0->tag != ge_tag) goto EndOfRule24;
tmp21 = ((ge_subtype) tmp0)->x;
tmp22 = ((ge_subtype) tmp0)->y;
x = tmp21;
y = tmp22;
# line 16 "interpreter.m"
  return evaluate(x) >= evaluate(y);
        
# line 129 "interpreter.cpp"
goto EndOfMatch50;
EndOfRule24 : ;
}
{
Expression tmp27;
Expression x;
Expression tmp25;
Expression y;
Expression tmp26;
if (tmp0->tag != plus_tag) goto EndOfRule28;
tmp25 = ((plus_subtype) tmp0)->x;
tmp26 = ((plus_subtype) tmp0)->y;
x = tmp25;
y = tmp26;
# line 17 "interpreter.m"
  return evaluate(x) +  evaluate(y);
        
# line 147 "interpreter.cpp"
goto EndOfMatch50;
EndOfRule28 : ;
}
{
Expression tmp31;
Expression x;
Expression tmp29;
Expression y;
Expression tmp30;
if (tmp0->tag != minus_tag) goto EndOfRule32;
tmp29 = ((minus_subtype) tmp0)->x;
tmp30 = ((minus_subtype) tmp0)->y;
x = tmp29;
y = tmp30;
# line 18 "interpreter.m"
  return evaluate(x) -  evaluate(y);
        
# line 165 "interpreter.cpp"
goto EndOfMatch50;
EndOfRule32 : ;
}
{
Expression tmp35;
Expression x;
Expression tmp33;
Expression y;
Expression tmp34;
if (tmp0->tag != mult_tag) goto EndOfRule36;
tmp33 = ((mult_subtype) tmp0)->x;
tmp34 = ((mult_subtype) tmp0)->y;
x = tmp33;
y = tmp34;
# line 19 "interpreter.m"
  return evaluate(x) *  evaluate(y);
        
# line 183 "interpreter.cpp"
goto EndOfMatch50;
EndOfRule36 : ;
}
{
Expression tmp39;
Expression x;
Expression tmp37;
Expression y;
Expression tmp38;
if (tmp0->tag != divide_tag) goto EndOfRule40;
tmp37 = ((divide_subtype) tmp0)->x;
tmp38 = ((divide_subtype) tmp0)->y;
x = tmp37;
y = tmp38;
# line 20 "interpreter.m"
  return evaluate(x) /  evaluate(y);
        
# line 201 "interpreter.cpp"
goto EndOfMatch50;
EndOfRule40 : ;
}
{
Expression tmp42;
Expression x;
Expression tmp41;
if (tmp0->tag != neg_tag) goto EndOfRule43;
tmp41 = ((neg_subtype) tmp0)->x;
x = tmp41;
# line 21 "interpreter.m"
  return - evaluate(x);
        
# line 215 "interpreter.cpp"
goto EndOfMatch50;
EndOfRule43 : ;
}
{
Expression tmp45;
int x;
int tmp44;
if (tmp0->tag != number_tag) goto EndOfRule46;
tmp44 = ((number_subtype) tmp0)->x;
x = tmp44;
# line 22 "interpreter.m"
  return x;
        
# line 229 "interpreter.cpp"
goto EndOfMatch50;
EndOfRule46 : ;
}
{
Expression tmp48;
int x;
int tmp47;
if (tmp0->tag != name_tag) goto EndOfRule49;
tmp47 = ((name_subtype) tmp0)->location;
x = tmp47;
# line 23 "interpreter.m"
  return var[x];
    
# line 243 "interpreter.cpp"
goto EndOfMatch50;
EndOfRule49 : ;
}
MatchError("interpreter.m", 10);
EndOfMatch50 : ;
}
# line 24 "interpreter.m"

}

void execute (Statement s)
{
    
# line 257 "interpreter.cpp"

// GENERATED FROM SOURCE LINE 29
{
Statement tmp51;
tmp51 = s;
{
Statement tmp55;
Expression tmp53;
int x;
int tmp52;
Expression rhs;
Expression tmp54;
if (tmp51->tag != assignment_tag) goto EndOfRule56;
tmp53 = ((assignment_subtype) tmp51)->lhs;
tmp54 = ((assignment_subtype) tmp51)->rhs;
if (tmp53->tag != name_tag) goto EndOfRule56;
tmp52 = ((name_subtype) tmp53)->location;
x = tmp52;
rhs = tmp54;
# line 30 "interpreter.m"
 
	    var[x] = evaluate(rhs);
        
# line 281 "interpreter.cpp"
goto EndOfMatch75;
EndOfRule56 : ;
}
{
Statement tmp58;
Expression x;
Expression tmp57;
if (tmp51->tag != print_tag) goto EndOfRule59;
tmp57 = ((print_subtype) tmp51)->x;
x = tmp57;
# line 32 "interpreter.m"

            printf("%d\n", evaluate(x));
        
# line 296 "interpreter.cpp"
goto EndOfMatch75;
EndOfRule59 : ;
}
{
Statement tmp63;
Expression c;
Expression tmp60;
Statement s1;
Statement tmp61;
Statement s2;
Statement tmp62;
if (tmp51->tag != ifstmt_tag) goto EndOfRule64;
tmp60 = ((ifstmt_subtype) tmp51)->cond;
tmp61 = ((ifstmt_subtype) tmp51)->thenpart;
tmp62 = ((ifstmt_subtype) tmp51)->elsepart;
c = tmp60;
s1 = tmp61;
s2 = tmp62;
# line 34 "interpreter.m"

            if(evaluate(c)) execute(s1); else execute(s2);
        
# line 319 "interpreter.cpp"
goto EndOfMatch75;
EndOfRule64 : ;
}
{
Statement tmp67;
Expression c;
Expression tmp65;
Statement s;
Statement tmp66;
if (tmp51->tag != whilestmt_tag) goto EndOfRule68;
tmp65 = ((whilestmt_subtype) tmp51)->cond;
tmp66 = ((whilestmt_subtype) tmp51)->body;
c = tmp65;
s = tmp66;
# line 36 "interpreter.m"

            while(evaluate(c)) execute(s);
        
# line 338 "interpreter.cpp"
goto EndOfMatch75;
EndOfRule68 : ;
}
{
Statement tmp71;
Statement s1;
Statement tmp69;
Statement s2;
Statement tmp70;
if (tmp51->tag != seq_tag) goto EndOfRule72;
tmp69 = ((seq_subtype) tmp51)->s1;
tmp70 = ((seq_subtype) tmp51)->s2;
s1 = tmp69;
s2 = tmp70;
# line 38 "interpreter.m"

            execute(s1); execute(s2);
        
# line 357 "interpreter.cpp"
goto EndOfMatch75;
EndOfRule72 : ;
}
{
Statement tmp73;
if (tmp51->tag != empty_tag) goto EndOfRule74;
# line 40 "interpreter.m"

            ;
    
# line 368 "interpreter.cpp"
goto EndOfMatch75;
EndOfRule74 : ;
}
MatchError("interpreter.m", 29);
EndOfMatch75 : ;
}
# line 42 "interpreter.m"

}
