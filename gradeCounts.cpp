#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <string>
#include <vector>

using namespace std;

//����ɼ��ṹ��
struct Student_info{
	string name;
	double midterm, final;
	vector<double> homework;
};

//ƽʱ�ɼ�����ȡ
istream& read_hw(istream& in, vector<double>& hw)
{
	if (in)
	{
		hw.clear();
		double x;
		while(in >> x)
			hw.push_back(x);
		in.clear();
	}
	return in;
}

//������������
istream& read(istream& is, Student_info& s)
{
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}

//��������ĸ����
bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

//������ֵ
double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2: vec[mid];
}

//����ɼ��Ĺ�ʽ
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}


double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("students has done no homework");
	return grade(midterm, final, median(hw));
}

//����ɼ��ĺ���
double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}

int main(void)
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	cout << "please enter students info:" << endl;

	//��������ѧ����Ϣ�����У���ĩ��ƽʱ�ɼ�
	while(read(cin, record)){
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	//�����ֵ�����ĸ��ѧ������
	sort(students.begin(), students.end(),compare);

	cout << "students' final grade are:"<<endl;

	//����ɼ�������ʾ����
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++ i)
	{
		//cout << setw(maxlen + 1) << students[i].name;
		string whitespace(maxlen + 1 - students[i].name.size(), ' ');
		cout << students[i].name << whitespace;
		try{
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << setw(8) << final_grade 
				<< setprecision(prec)<< endl;
		}catch(domain_error){
			cout << endl << "you must enter your grades. "
				"please try again." << endl;
			return 1;
		}
	}
	return 0; 
}
