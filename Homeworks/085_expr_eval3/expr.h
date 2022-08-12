#include <sstream>

class Expression{
public:
	Expression(){};
	virtual std::string toString() const = 0;
	virtual long evaluate() const = 0;
	virtual ~Expression(){};
};

class NumExpression : public Expression{
private:
	long number;
public:
	NumExpression(long x):number(x){};	  
	virtual std::string toString() const {
		std::stringstream ss;
		ss<<number;
		return ss.str();
	}
	virtual long evaluate() const{
		return number;
	}
	virtual ~NumExpression(){};
};

class arithExpression : public Expression{
protected://KeyPoint: U must delcare the fileds as protected so that the subclass can access them.
	Expression * left;
	Expression * right;
public:
	arithExpression(Expression * lhs, Expression * rhs):left(lhs),right(rhs){};
	virtual std::string toString() const = 0;
	virtual long evaluate() const = 0;
	virtual ~arithExpression(){
		delete left;
		delete right;
	};
};

class PlusExpression : public arithExpression{
public:
	PlusExpression(Expression * lhs, Expression * rhs):arithExpression(lhs, rhs){};
	virtual std::string toString() const {
		std::stringstream plu;
		plu<<"("<<left->toString()<<"+"<<right->toString()<<")";
		return plu.str();
	}
	virtual long evaluate() const {
		return left->evaluate() + right->evaluate();
	}
	virtual ~PlusExpression(){};
};

class MinusExpression : public arithExpression{
public:
	MinusExpression(Expression * lhs, Expression * rhs):arithExpression(lhs, rhs){};
	virtual std::string toString() const {
		std::stringstream minu;
		minu<<"("<<left->toString()<<"-"<<right->toString()<<")";
		return minu.str();
	}
	virtual long evaluate() const {
		return left->evaluate() - right->evaluate();
	}
	virtual ~MinusExpression(){};
};

class TimesExpression : public arithExpression{
public:
	TimesExpression(Expression * lhs, Expression * rhs):arithExpression(lhs, rhs){};
	virtual std::string toString() const {
		std::stringstream tim;
		tim<<"("<<left->toString()<<"*"<<right->toString()<<")";
		return tim.str();
	}
	virtual long evaluate() const {
		return left->evaluate() * right->evaluate();
	}
	virtual ~TimesExpression(){};
};

class DivExpression : public arithExpression{
public:
	DivExpression(Expression * lhs, Expression * rhs):arithExpression(lhs, rhs){};
	virtual std::string toString() const {
		std::stringstream div;
		div<<"("<<left->toString()<<"/"<<right->toString()<<")";
		return div.str();
	}
	virtual long evaluate() const {
		return left->evaluate() / right->evaluate();
	}
	virtual ~DivExpression(){};
};
