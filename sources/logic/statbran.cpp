#include <regex>
#include <memory>
#include "statfunc.hpp"
#include "branch.hpp"
#include "mapman.hpp"
#include "stackman.hpp"
#include "condvec.hpp"
#include "condition.hpp"
#include "instrvector.hpp"
#include "instruction.hpp"

bool games::statfunc::branch::bif(void* object, const std::string& line, void* unused) {
    std::smatch match;
    if (std::regex_match(line, match, std::regex("(.*?)(\\[)(.*?)(\\])"))) { //CONDITION[..] or CONDITIONSET[..]
        auto search = games::mapman::branmap.find(match[1]);
        if (search != games::mapman::branmap.end()) {
            void*       backup_object = games::mapman::branmap[match[1]].object();
            std::string backup_string = games::mapman::branmap[match[1]].args();
            void*       backup_result = games::mapman::branmap[match[1]].result();
            auto new_result = new std::shared_ptr <interfaces::conditional> ();
            games::mapman::branmap[match[1]].setObject(object);
            games::mapman::branmap[match[1]].setArgs(line);
            games::mapman::branmap[match[1]].setResult(new_result);

            auto target = (games::branch*) object;
            auto new_ivect = std::make_shared <games::instrvector> ();
            games::stackman::insvstack.push_back(new_ivect);
            //assign new params? setObject, setArgs, setResult
            games::mapman::branmap[match[1]].execute();

            target->branches.push_back(new_ivect);
            target->evals.push_back(*new_result);

            delete new_result;
            games::mapman::branmap[match[1]].setObject(backup_object);
            games::mapman::branmap[match[1]].setArgs(backup_string);
            games::mapman::branmap[match[1]].setResult(backup_result);

            return true;
        }
        else {
            std::cout << "[e] Error while building condition from " << line << std::endl;
            std::cout << "[e] Unknown identifier '" << match[1] << "'" << std::endl;
        }
    }

    return false;
}

bool games::statfunc::branch::belif(void* object, const std::string& line, void* unused) {
    std::smatch match;
    if (std::regex_match(line, std::regex("(.*?)(\\[)(.*?)(\\])"))) { //CONDITION[..] or CONDITIONSET[..]
        auto search = games::mapman::branmap.find(match[1]);
        if (search != games::mapman::branmap.end()) {
            void*       backup_object = games::mapman::branmap[match[1]].object();
            std::string backup_string = games::mapman::branmap[match[1]].args();
            void*       backup_result = games::mapman::branmap[match[1]].result();
            auto new_result = new std::shared_ptr <interfaces::conditional> ();
            games::mapman::branmap[match[1]].setResult(new_result);

            games::stackman::insvstack.pop_back();

            auto target = (games::branch*) object;
            auto new_ivect = std::make_shared <games::instrvector> ();
            games::stackman::insvstack.push_back(new_ivect);
            //assign new params? setObject, setArgs, setResult
            games::mapman::branmap[match[1]].execute();

            target->branches.push_back(new_ivect);
            target->evals.push_back(*new_result);

            delete[] new_result;
            games::mapman::branmap[match[1]].setObject(backup_object);
            games::mapman::branmap[match[1]].setArgs(backup_string);
            games::mapman::branmap[match[1]].setResult(backup_result);

            return true;
        }
        else {
            std::cout << "[e] Error while building condition from " << line << std::endl;
            std::cout << "[e] Unknown identifier '" << match[1] << "'" << std::endl;
        }
    }

    return false;
}

bool games::statfunc::branch::belse(void* object, const std::string& line, void* unused) {
    games::stackman::insvstack.pop_back();
    auto target = (games::branch*) object;
    auto new_ivect = std::make_shared <games::instrvector> ();
    auto new_cvect = std::make_shared <games::condvec> ();

    target->branches.push_back(new_ivect);
    target->evals.push_back(new_cvect);

    return true;
}

bool games::statfunc::branch::btrue(void* object, const std::string& line, void* unused) {
    return true;
}

bool games::statfunc::branch::bfalse(void* object, const std::string& line, void* unused) {
    return false;
}

bool games::statfunc::branch::bcond(void* object, const std::string& line, void* result) {
    std::smatch match;
    if (std::regex_match(line, match, std::regex("(CONDITION\\[)(.*?)(\\])"))) {
        auto target = (std::shared_ptr <games::condition>*) result;
        auto new_cond = std::make_shared <games::condition> (match[2]);
        *target = new_cond;
        return true;
    }
    else {
        std::cout << "[e] Failed to build condition from " << line << std::endl;
    }

    return false;
}

bool games::statfunc::branch::bconv(void* object, const std::string& line, void* unused) {
    return false;
}


bool games::statfunc::branch::foreach(void* object, const std::string& line, void* result) {
    std::smatch match;
    if (std::regex_match(line, match, std::regex("(FOREACH\\[)(.*?)(,\\s+)(.*?)(\\]:)"))) {
        auto search = games::mapman::vectmap.find(match[2]);
        if (search != games::mapman::vectmap.end()) {
            auto var = games::mapman::varimap.find(match[4]);
            if (var != games::mapman::varimap.end()) {

            }
            else {
                std::cout << "[e] Unrecognised variable " << match[4] << std::endl;
            }
        }
        else {
            std::cout << "[e] Unrecognised vector " << match[2] << std::endl;
        }
    }
    else {
        std::cout << "[e] Failed to build branch from " << line << std::endl;
    }

    return false;
}









