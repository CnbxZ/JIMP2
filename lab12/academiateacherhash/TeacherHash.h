//
// Created by KKK on 04.06.17.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>
#include <stdio.h>

using ::std::string;

namespace academia 
{
	class TeacherId 
	{

	public:

		TeacherId(int value);

		TeacherId();

		~TeacherId();

		operator int() const;

		bool operator!=(const TeacherId teacher) const;

		bool operator==(const TeacherId &other_teacher) const;

	private:
		int id_;
	};

	class Teacher 
	{
	public:

		Teacher(TeacherId id, string name, string place);

		bool operator!=(const Teacher teacher) const;

		bool operator==(const Teacher &other_teacher) const;

		TeacherId Id() const;

		string Department() const;

		string Name() const;

	private:

		TeacherId id_;

		string department_, name_, place_;

		int val;

	};
	class TeacherHash 
	{
	public:
		TeacherHash() {
		};

		size_t operator()(const Teacher &teacher) const;

	private:

	};
}

#endif //JIMP_EXERCISES_TEACHERHASH_H