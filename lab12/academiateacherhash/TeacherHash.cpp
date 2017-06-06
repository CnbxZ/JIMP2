//
// Created by KKK on 04.06.17.
//

using ::std::string;
using ::std::hash;

#include "TeacherHash.h"
#include <string.h>

namespace academia 
{
		TeacherId::TeacherId(int value) 
		{
			id_ = value;
		}

		TeacherId::TeacherId() 
		{
			id_ = 0;
		}

		TeacherId::operator int() const {
			return this->id_;
		}

		Teacher::Teacher(TeacherId value, string name, string place) {
			name_ = name;
			place_ = place;
			id_ = value;
		}

		bool TeacherId::operator!=(const TeacherId & other_id) const {
			if (this->id_ != other_id.id_) {
				return true;
			}
			return false;
		}

		TeacherId Teacher::Id() const 
		{
			return id_;
		}

		string Teacher::Name() const 
		{
			return name_;
		}

		string Teacher::Department() const 
		{
			return place_;
		}

		bool Teacher::operator!=(const Teacher teacher) const 
		{
			if (name_ == teacher.Name() and place_ == teacher.Department() 
				and id_ == teacher.Id()) return false;
			else true;
		}

		size_t TeacherHash::operator()(const Teacher &teacher) const
		{
			return (hash<int>{}(teacher.Id()) +
				hash<string>{}(teacher.Name()) +
				hash<string>{}(teacher.Department()));
		}

		bool Teacher::operator==(const Teacher &other_teacher) const 
		{
			return !(*this != other_teacher);
		}
}