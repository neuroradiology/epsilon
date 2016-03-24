#ifndef POINCARE_COMMUTATIVE_OPERATION_H
#define POINCARE_COMMUTATIVE_OPERATION_H

#include <poincare/expression.h>

class CommutativeOperation : public Expression {
  public:
    CommutativeOperation(Expression * first_operand, Expression * second_operand);
    ~CommutativeOperation();
    Expression * operand(int i);
    int numberOfOperands();
    float approximate(Context& context) override;
  protected:
    virtual float operateApproximatevelyOn(float a, float b) = 0;
  private:
    int m_numberOfOperands;
    Expression ** m_operands;
};

#endif