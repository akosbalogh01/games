#include <functional>
#include "command.hpp"
#include "argvectoridx.hpp"
#include "argvectorcmds.hpp"
#include "logic.hpp"
#include "interpreters.hpp"


void games::logic::pushDefaultCommands() {
    std::shared_ptr <games::logic> target_obj(this);

    std::function <void (games::logic*, bool)> fquit = setRunning;

    std::shared_ptr <interfaces::triggerable> cmd_quit = std::make_shared <games::command <games::logic, bool>> (fquit);
    (dynamic_cast <games::command <games::logic, bool>*> (cmd_quit.get()))->setTarget(target_obj);
    (dynamic_cast <games::command <games::logic, bool>*> (cmd_quit.get()))->setArgument(false);
    (dynamic_cast <games::command <games::logic, bool>*> (cmd_quit.get()))->pushRegexpPattern("exit");
    (dynamic_cast <games::command <games::logic, bool>*> (cmd_quit.get()))->pushRegexpPattern("quit");
    logic_commands.push_back(cmd_quit);

    std::function <void (games::logic*, std::string)> fload = loadConfig;
    std::shared_ptr <interfaces::triggerable> cmd_load = std::make_shared <games::argvcommand <games::logic, std::string>> (fload, games::argvindex(1));
    (dynamic_cast <games::command <games::logic, std::string>*> (cmd_load.get()))->setTarget(target_obj);
    //(dynamic_cast <games::command <games::logic, std::string>*> (cmd_load.get()))->setArgument("lofasz");
    (dynamic_cast <games::command <games::logic, std::string>*> (cmd_load.get()))->pushRegexpPattern("load *");
    logic_commands.push_back(cmd_load);

}
