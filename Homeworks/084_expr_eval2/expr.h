#include <sstream>

class Expression{
public:
	Expression(){};
	virtual std::string toString() const = 0;
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
	virtual ~NumExpression(){};
};

class arithExpression : public Expression{
	protected://KeyPoint: U must delcare the fileds as protected so that the subclass can access them.
	Expression * left;
	Expression * right;
/*
private:
	Expression * left;
	Expression * right;
*/	
public:
	/*	
	Expression * left;
	Expression * right;
	*/
	arithExpression(Expression * lhs, Expression * rhs):left(lhs),right(rhs){};
	virtual std::string toString() const = 0;
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
	virtual ~PlusExpression(){
		/*
		delete left;
		delete right;
		*/
	}
};

class MinusExpression : public arithExpression{
public:
	MinusExpression(Expression * lhs, Expression * rhs):arithExpression(lhs, rhs){};
	virtual std::string toString() const {
		std::stringstream minu;
		minu<<"("<<left->toString()<<"-"<<right->toString()<<")";
		return minu.str();
	}
	virtual ~MinusExpression(){
		/*
		delete left;
		delete right;
		*/
	}
};

class TimesExpression : public arithExpression{
public:
	TimesExpression(Expression * lhs, Expression * rhs):arithExpression(lhs, rhs){};
	virtual std::string toString() const {
		std::stringstream tim;
		tim<<"("<<left->toString()<<"*"<<right->toString()<<")";
		return tim.str();
	}
	virtual ~TimesExpression(){
		/*
		delete left;
		delete right;
		*/
	}
};

class DivExpression : public arithExpression{
public:
	DivExpression(Expression * lhs, Expression * rhs):arithExpression(lhs, rhs){};
	virtual std::string toString() const {
		std::stringstream div;
		div<<"("<<left->toString()<<"/"<<right->toString()<<")";
		return div.str();
	}
	virtual ~DivExpression(){
		/*
		delete left;
		delete right;
		*/
	}
};
