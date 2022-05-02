void BlueJay::Technical::server_callbacks::login_handler(
    served::response& res,
    const served::request& req) {
   using namespace BlueJay::Technical::Persistence;
   if (req.header("Content-Type") != "application/json") {
      served::response::stock_reply(400, res);
      return;
   };
   Credentials example = Credentials("Jared", "Passwrd");
   utils::CredentialsPayload parsed =
       utils::parseBody(utils::split<2>(req.body(), "&"));
   for(std::string value : parsed) {
      std::cout << value << std::endl;
   }
   // req.body() => parseBody(std::string, "&", "=")

   //const auto& [name, password] = utils::split<2>(req.body(), "&");
   //std::cout << name << " " << password << std::endl;
   //const auto& [_, name_value] = utils::split<2>(name, "=");
   //const auto& [__, password_value] = utils::split<2>(password, "=");

   //std::cout << name_value << std::endl;
   //std::cout << password_value << std::endl;
}
