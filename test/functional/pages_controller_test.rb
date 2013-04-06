require 'test_helper'

class PagesControllerTest < ActionController::TestCase
  test "should get team" do
    get :team
    assert_response :success
  end

  test "should get terms" do
    get :terms
    assert_response :success
  end

  test "should get what" do
    get :what
    assert_response :success
  end

end
