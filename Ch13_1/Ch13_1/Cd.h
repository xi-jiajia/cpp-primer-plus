#ifndef CLASSIC_H_
#define CLASSIC_H_

class Cd
{
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	Cd(const char* s1, const char* s2, int n, double x);
	Cd(const Cd& d);
	Cd();
	virtual ~Cd();
	virtual void Report() const;
	Cd& operator= (const Cd& d);
};

class Classic : public Cd
{
private:
	char works[50];
public:
	Classic(const char* s1, const char* s2, const char* s3, int n, double x);
	Classic(const Cd& c);
	Classic();
	~Classic() {};
	virtual void Report() const;
	Classic& operator=(const Classic& c);
};

#endif