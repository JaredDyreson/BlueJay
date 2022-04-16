void pos::server_callbacks::login_handler(served::response& res,
                                          const served::request& req) {
   if (req.header("Content-Type") != "application/json") {
      served::response::stock_reply(400, res);
      return;
   };
   const auto& [name, password] = utils::split<2>(req.body(), "&");
   std::cout << name << " " << password << std::endl;
   const auto& [_, name_value] = utils::split<2>(name, "=");
   const auto& [__, password_value] = utils::split<2>(password, "=");

   std::cout << name_value << std::endl;
   std::cout << password_value << std::endl;
}
